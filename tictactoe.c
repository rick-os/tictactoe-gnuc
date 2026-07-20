#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

void printMatQuad(int n, int mat[n][n]);
int whoWon(int n, int mat[n][n]);
int verifyCol(int n, int mat[n][n]);
int verifyRow(int n, int mat[n][n]);
int verifyMainDiagonal(int n, int mat[n][n]);
int verifySideDiagonal(int n, int mat[n][n]);

int main()
{
  int mat[3][3];
  char confirm;
  int usr1Col, usr1Row, usr2Col, usr2Row;
  int i, j, count;
  int winner;
  do 
  {
    for(i = 0; i<3; i++)
    {
      for(j=0; j<3;j++)
      {
        mat[i][j] = 0;
      }
    }

    bool end = false, valid = true;
    i = 0;

    do
    {
      valid = true;
      printMatQuad(3, mat);

      if(i%2 == 0)
      {
        do
        {
          do 
          {
            printf("Player 1, insert the row that you want to place your number: ");
            scanf("%d", &usr1Row);
            if(usr1Row < 1 || usr1Row > 3)
            {
               printf("Invalid row, insert a row between 1 and 3.\n");
            }
          }while(usr1Row < 1 || usr1Row > 3);

          do 
          {
            printf("Player 1, insert the column that you want to place your number: ");
            scanf("%d", &usr1Col);
            if(usr1Col < 1 || usr1Col > 3)
            {
              printf("Invalid column, insert a number between 1 and 3.\n");
            }
          }while(usr1Col < 1 || usr1Col > 3);

          if(mat[usr1Row-1][usr1Col-1] != 0)
          {
            printf("Invalid play, place your number where there's zeros.\n");
            valid = false;
          }
          else
          {
            mat[usr1Row-1][usr1Col-1] = 1;
            valid = true;
          }
        }while(!valid);
      }
      else
      {
        do
        {
          do 
          {
            printf("Player 2, insert the column that you want to place your number: ");
            scanf("%d", &usr2Row);
            if(usr2Row < 1 || usr2Row > 3)
            {
              printf("Invalid row, insert a row between 1 and 3.\n");
            }
          }while(usr2Row < 1 || usr2Row > 3);

          do 
          {
            printf("Player 2, insert the column that you want to place your number: ");
            scanf("%d", &usr2Col);
            if(usr2Col < 1 || usr2Col > 3)
            {
              printf("Invalid column, insert a number between 1 and 3.\n");
            }
          }while(usr2Col < 1 || usr2Col > 3);

          if(mat[usr2Row-1][usr2Col-1] != 0)
          {
            printf("Invalid play, place your number where there's zeros.\n");
            valid = false;
          }
          else
          {
            mat[usr2Row-1][usr2Col-1] = 2;
            valid = true;
          }

        }while(!valid);
      }
      if(i>3)
      {
        winner = whoWon(3,mat);
        if(winner != 0 || i == 8)
        {
          end = true;
        }
      }
      i++;
    }while(!end == true);
    
    printMatQuad(3,mat);
    if(winner != 0)
    {
      printf("Player %d has won!!\n", winner);
    }
    else 
    {
      printf("Nobody won!\n");
    }

    __fpurge(stdin);
    printf("Wants to play again? (y/n)");
    scanf(" %c", &confirm);
  } while(confirm == 'y' || confirm == 'Y');

  return 0;
}

// Simple print for 
void printMatQuad(int n, int mat[n][n])
{
  int i, j;
  
  // Making the header
  printf("\t");
  for(i=1;i <= n; i++)
  {
    printf("%2d\t", i);
  }
  printf("\n");

  for(i=0; i<n; i++)
  {
    printf("%d:\t", i+1);
    for(j=0; j<n; j++)
    {
      printf("%2d\t", mat[i][j]);
    }
    printf("\n");
  }
}
// Verify every case using smaller functions below. It's the best thing i could
// think to verify if somebody has won.
int whoWon(int n, int mat[n][n])
{
  int winner;

  winner = verifyMainDiagonal(n, mat);

  if(winner != 0)
  {
    return winner;
  }
  else 
  {
    winner = verifySideDiagonal(n,mat);
    if(winner != 0)
    {
      return winner;
    }
    else
    {
      winner = verifyRow(n,mat);
      if(winner != 0)
      {
        return winner;
      }
      else
      {
        winner = verifyCol(n,mat);

        return winner;
      }
    }
  }
}
// checks if numbers at the same row are equals.
int verifyRow(int n, int mat[n][n])
{
  int i, j, valid = 0;

  for(i=0; i<n; i++)
  {
    for(j=1; j<n;j++)
    {
      if(mat[i][j-1] == mat[i][j])
      {
        valid = 1;
      }
      else 
      {
        valid = 0;
        break;
      }
    }
    if(valid == 1)
    {
      return mat[i][0];
    }
  }
  return 0;
}
// cheks if number at the same column are equals.
int verifyCol(int n, int mat[n][n])
{
  int i, j, valid = 0;

  for(i=0; i<n;i++)
  {
    for(j=1;j<n;j++)
    {
      if(mat[j-1][i] == mat[j][i])
      {
        valid = 1;
      }
      else
      {
        valid = 0;
        break;
      }
    }
    if(valid == 1)
    {
      return mat[0][i];
    }
  }
  return 0;
}
// check if numbers at main diagonal are equals.
int verifyMainDiagonal(int n, int mat[n][n])
{
  int i, valid = 0;

  for(i=1;i<n;i++)
  {
    if(mat[i-1][i-1] == mat[i][i])
    {
      valid=1;
    }
    else
    {
      valid = 0;
      break;
    }
  }
  if(valid == 1)
  {
    return mat[0][0];
  }

  return 0;
}
// Checks if number at side diagonal are equals.
int verifySideDiagonal(int n, int mat[n][n])
{

  int i, valid = 0;

  for(i=1; i<n; i++)
  {
    if(mat[i-1][n-i] == mat[i][n-1-i])
    {
      valid = 1;
    }
    else
    {
      valid = 0;
      break;
    }
  }
  if(valid == 1)
  {
    return mat[0][n-1];
  }
  return 0;
}
