def bfs(graph, start_node):
    visited = set()
    queue = []

    queue.append(start_node)

    while queue:
        current_node = queue.pop(0)
        print(current_node)  # Process the current node (or perform other operations)

        if current_node not in visited:
            visited.add(current_node)
            neighbors = graph[current_node]

            for neighbor in neighbors:
                if neighbor not in visited:
                    queue.append(neighbor)

# Example graph represented as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

start_node = 'A'
bfs(graph, start_node)
