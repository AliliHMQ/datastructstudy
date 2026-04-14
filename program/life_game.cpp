#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN() system("cls")
#else
    #include <unistd.h>
    #define CLEAR_SCREEN() system("clear")
#endif

class GameOfLife {
private:
    int rows, cols;
    std::vector<std::vector<bool>> grid;      // 当前代
    std::vector<std::vector<bool>> nextGrid;  // 下一代

    // 计算 (x,y) 周围活细胞数量（不处理边界外，边界外视为死）
    int countLiveNeighbors(int x, int y) const {
        int live = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    if (grid[nx][ny]) live++;
                }
            }
        }
        return live;
    }

public:
    // 构造函数：创建 rows×cols 的网格，默认全部死
    GameOfLife(int r, int c) : rows(r), cols(c) {
        grid.assign(rows, std::vector<bool>(cols, false));
        nextGrid.assign(rows, std::vector<bool>(cols, false));
    }

    // 随机初始化：每个细胞以概率 prob 为活
    void randomInit(double prob = 0.2) {
        std::srand(std::time(nullptr));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = (std::rand() / double(RAND_MAX)) < prob;
            }
        }
    }

    // 预置一个有趣的模式：滑翔机枪 (Gosper Glider Gun)
    // 需要网格足够大（建议至少 40x40），这里只设置部分，超出边界会自动忽略
    void setGliderGun(int offsetX = 1, int offsetY = 1) {
        // 经典滑翔机枪的活细胞坐标（相对偏移）
        std::vector<std::pair<int,int>> pattern = {
            {1,5}, {1,6}, {2,5}, {2,6},
            {11,5}, {11,6}, {11,7}, {12,4}, {12,8}, {13,3}, {13,9}, {14,3}, {14,9},
            {15,6}, {16,4}, {16,8}, {17,5}, {17,6}, {17,7}, {18,6},
            {21,3}, {21,4}, {22,3}, {22,4}, {21,1}, {22,1}, {21,2}, {22,2},
            {25,2}, {25,3}, {26,2}, {26,3}
        };
        for (auto [x,y] : pattern) {
            int nx = offsetX + x;
            int ny = offsetY + y;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols)
                grid[nx][ny] = true;
        }
    }

    // 计算下一代
    void update() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int liveNeighbors = countLiveNeighbors(i, j);
                if (grid[i][j]) {
                    // 活细胞规则
                    nextGrid[i][j] = (liveNeighbors == 2 || liveNeighbors == 3);
                } else {
                    // 死细胞规则
                    nextGrid[i][j] = (liveNeighbors == 3);
                }
            }
        }
        // 交换当前代与下一代
        grid.swap(nextGrid);
    }

    // 打印当前网格到控制台
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << (grid[i][j] ? "█" : " ");
            }
            std::cout << "\n";
        }
        std::cout << std::flush;
    }

    // 获取当前代的活细胞数量（可选，用于调试）
    int countLive() const {
        int cnt = 0;
        for (const auto& row : grid)
            for (bool cell : row)
                if (cell) cnt++;
        return cnt;
    }

    // 运行游戏，逐代显示，按回车继续
    void runInteractive(int delayMs = 0) {
        bool running = true;
        while (running) {
            CLEAR_SCREEN();
            print();
            std::cout << "Generation: " << genCount << "  Live cells: " << countLive() << "\n";
            std::cout << "Press ENTER to step, q then ENTER to quit.\n";

            char input;
            std::cin.get(input);
            if (input == 'q' || input == 'Q')
                running = false;

            update();
            genCount++;
            if (delayMs > 0 && running) {
                std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            }
        }
    }

private:
    int genCount = 0;
};

int main() {
    // 设置网格大小（建议终端窗口足够大，如 40x80）
    const int ROWS = 30;
    const int COLS = 80;

    GameOfLife game(ROWS, COLS);

    // 选择初始化方式：随机 或 滑翔机枪
    std::cout << "Choose initialization:\n1 - Random (20% alive)\n2 - Glider Gun\n";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        game.randomInit(0.2);
    } else {
        // 将滑翔机枪放置在中央偏左上的位置
        game.setGliderGun(5, 10);
    }

    std::cin.ignore(); // 清除输入缓冲区
    game.runInteractive(0); // 0 表示手动步进，可以改为正数毫秒自动步进

    return 0;
}