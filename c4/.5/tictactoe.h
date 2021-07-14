#define BOARD_SIZE  3

typedef struct TurnTag
{
    int player;
    int x;
    int y;
} Turn;

void playgame(void);
void initturns(void);
void reqturn(void);
void reqfirstplayer(void);
Turn newturn(void);
int istie(void);
void initboard(void);
void drawboard(void);
void puttoken(int, int, int);
int haswinner(void);
