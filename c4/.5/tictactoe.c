void playgame()
{
    Turn *t;

    initboard();
    drawboard();

    while (!finished())
    {

        drawboard();
    }
}
