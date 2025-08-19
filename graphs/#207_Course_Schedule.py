class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = {i : [] for i in range(numCourses)}

        for course, pre in prerequisites:
            preMap[course].append(pre)
        
        visited = set()

        def dfs(course):
            # check for cycle
            if course in visited:
                return False
            # already checked condition
            if not preMap[course]:
                return True
            # add to set while checking neighbors
            visited.add(course)
            for c in preMap[course]:
                if not dfs(c):
                    return False
            # remove after checking neighbors
            visited.remove(course)
            # mark as checked
            preMap[course] = []
            return True

        for c in range(numCourses):
            if not dfs(c):
                return False
        return True
