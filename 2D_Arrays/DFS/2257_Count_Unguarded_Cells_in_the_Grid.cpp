// #define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
// #define INL __attribute__((always_inline))
// #define HOT __attribute__((hot))

// class Solution {
// private:
//     static constexpr uint MAXS = 100'000;
//     static constexpr uint MAXC = (MAXS + 31u) >> 5;
//     static constexpr uint64_t BIT_MASK = 0x5555555555555555ull;

//     enum object_t : uint8_t { empty = 0, spied, guard, wall };

//     alignas(64) static uint64_t grid[MAXC];

//     static object_t get(const uint idx) noexcept {
//         return static_cast<object_t>((grid[idx >> 5] >> ((idx & 31) << 1)) & 3u);
//     }

//     static void set(const uint idx, const object_t v) noexcept {
//         const uint shift = (idx & 31) << 1;
//         grid[idx >> 5] = (grid[idx >> 5] & ~(3ull << shift)) | (uint64_t(v) << shift);
//     }

// public:
//     static int countUnguarded(uint m, uint n, 
//                             const vector<vector<int>>& guards,
//                             const vector<vector<int>>& walls) noexcept {
//         const uint size = m * n;
//         const uint qsize = (size + 31u) >> 5;
        
//         __builtin_memset(grid, 0, qsize * sizeof(uint64_t));

//         const uint guard_size = guards.size();
//         const uint wall_size = walls.size();
        
//         if (__builtin_expect(guard_size + wall_size == size, 0)) return 0;
        
//         #pragma GCC unroll 4
//         for (uint i = 0; i < wall_size; ++i) {
//             set(walls[i][0] * n + walls[i][1], wall);
//         }
        
//         #pragma GCC unroll 4
//         for (uint i = 0; i < guard_size; ++i) {
//             set(guards[i][0] * n + guards[i][1], guard);
//         }

//         #pragma GCC unroll 2
//         for (uint g = 0; g < guard_size; ++g) {
//             const uint x = guards[g][0], y = guards[g][1];
            
//             for (uint i = x - 1u, d = i * n + y; i + 1u && get(d) <= spied; i--, d -= n)
//                 set(d, spied);
//             for (uint i = x + 1u, d = i * n + y; i < m && get(d) <= spied; i++, d += n)
//                 set(d, spied);
//             for (uint j = y - 1u, d = x * n + j; j + 1u && get(d) <= spied; j--, d--)
//                 set(d, spied);
//             for (uint j = y + 1u, d = x * n + j; j < n && get(d) <= spied; j++, d++)
//                 set(d, spied);
//         }

//         uint guarded = 0;
//         #pragma GCC unroll 8
//         for (uint k = 0; k < qsize; ++k) {
//             guarded += __builtin_popcountll((grid[k] | (grid[k] >> 1)) & BIT_MASK);
//         }

//         return size - guarded;
//     } 
// };

// alignas(64) uint64_t Solution::grid[MAXC];

// [[maybe_unused]] static const auto fast_io = []() noexcept {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     return 0;
// }();

/******************************************** C++ ********************************************/
//Approach-1 (Simple Simulation)
//T.C : O(m*n + G*(m+n)), where G =  size of guards
//S.C : O(m*n), considering the size of grid we took
class Solution {
public:

    void markGaurded(int row, int col, vector<vector<int>>& grid) {
        //UP
        for(int i = row-1; i >= 0; i--) {
            if(grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1; //Marking it as gaurded
        }

        //Down
        for(int i = row+1; i < grid.size(); i++) {
            if(grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1; //Marking it as gaurded
        }

        //left
        for(int j = col-1; j >= 0; j--) {
            if(grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            grid[row][j] = 1; //Marking it as gaurded
        }

        //right
        for(int j = col+1; j < grid[0].size(); j++) {
            if(grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            grid[row][j] = 1; //Marking it as gaurded
        }

    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        //mark gaurds positions
        for(vector<int>& vec : guards) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2; //gaurd
        }

        //mark walls positions
        for(vector<int>& vec : walls) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3; //wall 
        }

        for(vector<int>& gaurd : guards) {
            int i = gaurd[0];
            int j = gaurd[1];
            markGaurded(i, j, grid); //four directions me check karo and mark karo gaurded
        }

        int count = 0;
        //O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) { //ungaurded
                    count++;
                }
            }
        }

        return count;

    }
};


//Approach-2 (DFS)
//T.C : O(m*n + G*(m+n)), where G =  size of guards
//S.C : O(m*n), considering the size of grid we took
// class Solution {
// public:
//     void dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols, int direction) {
//         // Boundary check and skipping guarded or walled cells
//         if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2) {
//             return;
//         }

//         // Mark the current cell as visited by a guard's line of sight
//         grid[row][col] = 3;

//         // Continue the DFS in the specified direction
//         if (direction == 1) { // UP
//             dfs(grid, row - 1, col, rows, cols, direction);
//         } else if (direction == 2) { // DOWN
//             dfs(grid, row + 1, col, rows, cols, direction);
//         } else if (direction == 3) { // LEFT
//             dfs(grid, row, col - 1, rows, cols, direction);
//         } else { // RIGHT
//             dfs(grid, row, col + 1, rows, cols, direction);
//         }
//     }

//     int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         // Initialize the grid
//         vector<vector<int>> grid(rows, vector<int>(cols, 0));

//         // Mark guard positions
//         for (const auto& guard : guards) {
//             int i = guard[0];
//             int j = guard[1];
//             grid[i][j] = 1; // Guard cell
//         }

//         // Mark wall positions
//         for (const auto& wall : walls) {
//             int i = wall[0];
//             int j = wall[1];
//             grid[i][j] = 2; // Wall cell
//         }

//         // Perform DFS for each guard in all four directions (UP, DOWN, LEFT, RIGHT)
//         for (const auto& guard : guards) {
//             int guardRow = guard[0];
//             int guardCol = guard[1];

//             dfs(grid, guardRow - 1, guardCol, rows, cols, 1); // UP
//             dfs(grid, guardRow + 1, guardCol, rows, cols, 2); // DOWN
//             dfs(grid, guardRow, guardCol - 1, rows, cols, 3); // LEFT
//             dfs(grid, guardRow, guardCol + 1, rows, cols, 4); // RIGHT
//         }

//         // Count unguarded cells
//         int unguardedCount = 0;
//         for (int row = 0; row < rows; ++row) {
//             for (int col = 0; col < cols; ++col) {
//                 if (grid[row][col] == 0) {
//                     ++unguardedCount;
//                 }
//             }
//         }

//         return unguardedCount;
//     }
// };


