#include "raylib.h"
#include "Player.h"
#include "Ball.h"
#include "Screen.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    Screen screen_properties;

    InitWindow(screen_properties.screenWidth, screen_properties.screenHeight, "Raylib Pong");

    Player playerOne(100, screen_properties.screenHeight /2, 10, 40, 1);
    Player playerTwo(screen_properties.screenWidth - 100, screen_properties.screenHeight / 2, 10, 40, 2);

    Ball ball(screen_properties.screenWidth/2,screen_properties.screenHeight/2, 10);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
            
        if (ball.StartBall())
        {
            playerOne.resetRecentScore();
            playerTwo.resetRecentScore();
        }

        ball.CheckCollisions();

        
        ball.CheckCollisions_WPlayer({playerOne.GetPlayerObject().GetX(),playerOne.GetPlayerObject().GetY()},
            { playerOne.GetPlayerObject().GetWidth(),playerOne.GetPlayerObject().GetHeight() },
            playerOne.GetPlayerObject().GetVel());

        ball.CheckCollisions_WPlayer({ playerTwo.GetPlayerObject().GetX(),playerTwo.GetPlayerObject().GetY() },
            { playerTwo.GetPlayerObject().GetWidth(),playerTwo.GetPlayerObject().GetHeight() },
            playerTwo.GetPlayerObject().GetVel());
        


        playerOne.Move();
        playerTwo.Move();
        
        playerOne.CheckCollisions();
        playerTwo.CheckCollisions();

        playerOne.GetPlayerObject().UpdateObject();
        playerTwo.GetPlayerObject().UpdateObject();

        ball.GetBallObject().UpdateObject();

        playerOne.ScorePoints(ball.GetBallObject().GetX());
        playerTwo.ScorePoints(ball.GetBallObject().GetX());

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText(TextFormat(" %d", playerOne.GetScore()), screen_properties.screenWidth * 0.25, 30, 40, RAYWHITE);
        DrawText(TextFormat(" %d", playerTwo.GetScore()), screen_properties.screenWidth * 0.75, 30, 40, RAYWHITE);

        DrawLine(screen_properties.screenWidth / 2, 0, screen_properties.screenWidth / 2, screen_properties.screenHeight, RAYWHITE);

        playerOne.GetPlayerObject().DrawObject(1);

        playerTwo.GetPlayerObject().DrawObject(1);

        ball.GetBallObject().DrawObject(2);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}