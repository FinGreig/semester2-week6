void draw_grid(char **grid);
char **initialize_grid(void);
void add_point(char **grid, int x, int y);
void move_point(int *x, int *y, int dx, int dy);
void reflect_point(int *x, int *y, char axis);
void swap_coords(int *x, int *y);