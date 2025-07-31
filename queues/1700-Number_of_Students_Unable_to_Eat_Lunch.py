class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        queue = deque(students)
        n = len(students)
        for sandwich in sandwiches:
            count = 0
            while count < n and queue[0] != sandwich:
                count += 1
                student = queue.popleft()
                queue.append(student)
            if queue[0] == sandwich:
                n -= 1
                queue.popleft()
            else:
                break
        return n

