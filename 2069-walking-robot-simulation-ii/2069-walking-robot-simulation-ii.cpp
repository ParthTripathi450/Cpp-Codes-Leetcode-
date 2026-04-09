class Robot {
    const int DIRS[4][2]      = {{0,1},{1,0},{0,-1},{-1,0}};
    const string DIR_NAMES[4] = {"North","East","South","West"};

    int width, height, strides;
    int x = 0, y = 0, direction = 1;

public:
    Robot(int width, int height)
        : width(width), height(height),
          strides(2 * (width - 1) + 2 * (height - 1)) {}

    void step(int num) {
        num %= strides;
        if (num == 0) num = strides;

        while (num > 0) {
            int newX = x + DIRS[direction][0];
            int newY = y + DIRS[direction][1];

            if (newX < 0 || newX >= width || newY < 0 || newY >= height) {
                direction = (direction + 3) % 4;
                continue;
            }

            x = newX; y = newY;
            num--;
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() { return DIR_NAMES[direction]; }
};