use std::rc::Rc;
use std::cell::RefCell;

type Link = Option<Rc<RefCell<Node>>>;

struct Node {
    val: i32,
    next: Link,
    prev: Link,
}

impl Node {
    fn new(val: i32) -> Rc<RefCell<Self>> {
        Rc::new(RefCell::new(Node {
            val,
            next: None,
            prev: None,
        }))
    }
}

pub struct MyLinkedList {
    head: Link,
    tail: Link,
    size: usize,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyLinkedList {

    fn new() -> Self {
        MyLinkedList {
            head: None,
            tail: None,
            size: 0,
        }
    }
    
    fn get(&self, index: i32) -> i32 {
        if index < 0 || index as usize >= self.size {
            return -1;
        }

        let mut current = self.head.clone();

        for _ in 0..index {
            let next = current.as_ref().unwrap().borrow().next.clone();
            current = next;
        }

        current.unwrap().borrow().val
    }
    
    fn add_at_head(&mut self, val: i32) {
        let new_node = Node::new(val);

        match self.head.take() {
            Some(old_head) => {
                old_head.borrow_mut().prev = Some(new_node.clone());
                new_node.borrow_mut().next = Some(old_head);
                self.head = Some(new_node);
            }
            None => {
                self.head = Some(new_node.clone());
                self.tail = Some(new_node);
            }
        }
        self.size += 1;
    }
    
    fn add_at_tail(&mut self, val: i32) {
        let new_node = Node::new(val);

        match self.tail.take() {
            Some(old_tail) => {
                old_tail.borrow_mut().next = Some(new_node.clone());
                new_node.borrow_mut().prev = Some(old_tail);
                self.tail = Some(new_node);
            }
            None => {
                self.head = Some(new_node.clone());
                self.tail = Some(new_node);
            }
        }
        self.size += 1;
    }
    
    fn add_at_index(&mut self, index: i32, val: i32) {
        if index < 0 || index as usize > self.size {
            return;
        }
        if index == 0 {
            self.add_at_head(val);
            return;
        }
        if index as usize == self.size {
            self.add_at_tail(val);
            return;
        }
        let new_node = Node::new(val);
        let mut current = self.head.clone();

        for _ in 0..(index - 1) {
            let next = current.as_ref().unwrap().borrow().next.clone();
            current = next;
        }
        let current = current.unwrap();
        let next = current.borrow().next.clone();

        new_node.borrow_mut().prev = Some(current.clone());
        new_node.borrow_mut().next = next.clone();
        
        current.borrow_mut().next = Some(new_node.clone());
        next.unwrap().borrow_mut().prev = Some(new_node);
        self.size += 1;
    }
    
    pub fn delete_at_index(&mut self, index: i32) {
        if index < 0 || index as usize >= self.size {
            return;
        }
        
        if self.size == 1 {
            self.head = None;
            self.tail = None;
            self.size = 0;
            return;
        }
        
        if index == 0 {
            let head = self.head.take().unwrap();
            self.head = head.borrow().next.clone();
            if let Some(new_head) = &self.head {
                new_head.borrow_mut().prev = None;
            }
            self.size -= 1;
            return;
        }
        
        if index as usize == self.size - 1 {
            let tail = self.tail.take().unwrap();
            self.tail = tail.borrow().prev.clone();
            if let Some(new_tail) = &self.tail {
                new_tail.borrow_mut().next = None;
            }
            self.size -= 1;
            return;
        }
        
        let mut current = self.head.clone();
        for _ in 0..index {
            let next = current.as_ref().unwrap().borrow().next.clone();
            current = next;
        }
        
        let node_to_delete = current.unwrap();
        let prev = node_to_delete.borrow().prev.clone();
        let next = node_to_delete.borrow().next.clone();
        
        prev.as_ref().unwrap().borrow_mut().next = next.clone();

        next.unwrap().borrow_mut().prev = prev.clone();
        
        self.size -= 1;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * let obj = MyLinkedList::new();
 * let ret_1: i32 = obj.get(index);
 * obj.add_at_head(val);
 * obj.add_at_tail(val);
 * obj.add_at_index(index, val);
 * obj.delete_at_index(index);
 */


// more efficient implementation
use std::rc::{Rc, Weak};
use std::cell::RefCell;

struct Node {
    val: i32,
    next: Option<Rc<RefCell<Node>>>,
    prev: Option<Weak<RefCell<Node>>>,
}

struct MyLinkedList {
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Weak<RefCell<Node>>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyLinkedList {

    fn new() -> Self {
        Self {
            head: None,
            tail: None,
        }
    }
    
    fn get(&self, index: i32) -> i32 {
        let mut idx: i32 = 0;
        let mut head = self.head.as_ref().cloned();
        while let Some(h) = head {
            let n = h.borrow();
            if idx == index {
                return n.val;
            }
            idx += 1;
            head = n.next.as_ref().cloned();
        }
        -1
    }
    
    fn add_at_head(&mut self, val: i32) {
        let mut old_head = self.head.take();
        let mut new_head = Rc::new(RefCell::new(Node {
            val,
            next: None,
            prev: None,
        }));
        if let Some(h) = old_head {
            h.borrow_mut().prev = Some(Rc::downgrade(&new_head));
            new_head.borrow_mut().next = Some(h);
            self.head = Some(new_head);
        } else {
            self.tail = Some(Rc::downgrade(&new_head));
            self.head = Some(new_head);
        }
    }
    
    fn add_at_tail(&mut self, val: i32) {
        let mut old_tail = self.tail.take();
        let mut new_tail = Rc::new(RefCell::new(Node {
            val,
            next: None,
            prev: None,
        }));
        if let Some(tail) = old_tail.take() && let Some(t) = tail.upgrade() {
            // valid tail
            new_tail.borrow_mut().prev = Some(Rc::downgrade(&t));
            self.tail = Some(Rc::downgrade(&new_tail));
            t.borrow_mut().next = Some(new_tail);
        } else {
            // must be empty
            self.tail = Some(Rc::downgrade(&new_tail));
            self.head = Some(new_tail);
        }
    }
    
    fn add_at_index(&mut self, index: i32, val: i32) {
        if index == 0 {
            self.add_at_head(val);
            return;
        }

        let mut idx = 0;
        let mut cur = self.head.as_ref().cloned();
        let mut selected: Option<Weak<RefCell<Node>>> = None;
        while let Some(n) = cur {
            let n = n.borrow();
            if idx == index {
                // we're at the node we want to replace
                // so let's actually get the parent
                selected = n.prev.as_ref().cloned();
                break;
            }
            idx += 1;
            cur = n.next.as_ref().cloned();
        }
        if idx == index && selected.is_none() {
            // we are at tail
            self.add_at_tail(val);
            return;
        }

        if idx != index || selected.is_none() {
            return;
        }

        // this is a bit messy but now we can just move around pointers to solve
        // Option<Weak<RefCell<Node>>> -> Rc<RefCell<Node>>
        let mut parent = selected.unwrap().upgrade().unwrap();
        let mut p = parent.borrow_mut();
        let mut old_node = p.next.take().unwrap(); // should mean this is only Rc
        let mut new_node = Rc::new(RefCell::new(Node {
            val,
            next: Some(Rc::clone(&old_node)),
            prev: Some(Rc::downgrade(&parent)),
        }));
        old_node.borrow_mut().prev = Some(Rc::downgrade(&new_node));
        p.next = Some(new_node)
    }
    
    fn delete_at_index(&mut self, index: i32) {
        if index == 0 {
            let old_head = self.head.take();
            if let Some(h) = old_head {
                self.head = h.borrow_mut().next.take();
            }
            if let Some(h) = self.head.as_ref() {
                h.borrow_mut().prev = None;
            }
            return;
        }
        let mut idx = 0;
        let mut cur = self.head.as_ref().cloned();
        let mut selected: Option<Weak<RefCell<Node>>> = None;
        while let Some(n) = cur {
            let n = n.borrow();
            if idx == index {
                // we're at the node we want to replace
                // so let's actually get the parent
                selected = n.prev.as_ref().cloned();
                break;
            }
            idx += 1;
            cur = n.next.as_ref().cloned();
        }
        if idx != index || selected.is_none() {
            // we are at or past tail / nothing to do
            return;
        }

        let mut parent = selected.unwrap().upgrade().unwrap();
        let mut p = parent.borrow_mut();
        let mut old_node = Rc::try_unwrap(p.next.take().unwrap()).ok().unwrap().into_inner(); // should be valid here
        let new_node = old_node.next.take();
        if let Some(n) = new_node {
            n.borrow_mut().prev = Some(Rc::downgrade(&parent));
            p.next = Some(n);
            return;
        }
        // update tail ?
        self.tail = Some(Rc::downgrade(&parent));
        p.next = None;
    }
}
