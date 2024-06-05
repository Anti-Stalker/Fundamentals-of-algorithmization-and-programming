#include "find.h"

Find::Find() {}

std::vector<std::pair<int, int>> Find::aStar(int **a, int start_x, int start_y, int dest_x, int dest_y)
{
    std::vector<std::pair<int, int>> path;
    if (a[dest_x][dest_y] == 1) return path;
    int rows = 48;
    int cols = 24;

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<Node*>> parents(rows, std::vector<Node*>(cols, nullptr));

    std::priority_queue<Node*, std::vector<Node*>, CompareNode> open;
    open.push(new Node(start_x, start_y, 0, heuristic(start_x, start_y, dest_x, dest_y), nullptr));

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!open.empty())
    {
        Node* current = open.top();
        open.pop();

        if (current->x == dest_x && current->y == dest_y)
        {
            while (current != nullptr)
            {
                path.push_back(std::make_pair(current->x, current->y));
                current = current->parent;
            }
            break;
        }

        visited[current->x][current->y] = true;

        for (int i = 0; i < 4; i++)
        {
            int new_x = current->x + dx[i];
            int new_y = current->y + dy[i];

            if (isValid(new_x, new_y, rows, cols) && !visited[new_x][new_y] && a[new_x][new_y] != 1)
            {
                Node* newNode = new Node(new_x, new_y, current->g + 1, heuristic(new_x, new_y, dest_x, dest_y), current);
                open.push(newNode);
                parents[new_x][new_y] = newNode;
            }
        }
    }
    std::reverse(path.begin(), path.end());
    return path;
}
