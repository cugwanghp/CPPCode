#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Create a graph and indegree vector
    unordered_map<int, vector<int>> graph;
    vector<int> indegree(numCourses, 0);
    
    // Build the graph
    for (const auto& prereq : prerequisites) {
        graph[prereq[1]].push_back(prereq[0]); // prereq[1] -> prereq[0]
        indegree[prereq[0]]++;
    }

    // Queue for courses with no prerequisites (indegree of 0)
    queue<int> zeroIndegreeQueue;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            zeroIndegreeQueue.push(i);
        }
    }

    vector<int> order;
    
    while (!zeroIndegreeQueue.empty()) {
        int course = zeroIndegreeQueue.front();
        zeroIndegreeQueue.pop();
        order.push_back(course);

        // Decrease the indegree of neighboring courses
        for (const int& neighbor : graph[course]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                zeroIndegreeQueue.push(neighbor);
            }
        }
    }

    // If we were able to schedule all courses, return the order
    if (order.size() == numCourses) {
        return order;
    }

    // If not all courses can be scheduled, return an empty array
    return {};
}

// Example usage:
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{0, 1}, {0, 2}, {1, 3}};
    
    vector<int> order = findOrder(numCourses, prerequisites);
    
    // Output the result
    for (int course : order) {
        cout << course << " ";
    }
    cout << endl; // For better output formatting
    return 0;
}
