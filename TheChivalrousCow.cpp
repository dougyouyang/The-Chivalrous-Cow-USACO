//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <queue>

using namespace std;
queue<int> pox, poy, moves;
char mat[200][200];
int mo=0, visited[200][200];

void bfs(int row, int col)
{
    pox.push(row), poy.push(col), moves.push(0);
    while(!pox.empty()){
        int x=pox.front(), y=poy.front();
        pox.pop(), poy.pop();
        if(mat[x][y]=='H'){
            cout << moves.front() << endl;
            return;
        }
        if((mat[x+1][y+2]=='.' || mat[x+1][y+2]=='H') && !visited[x+1][y+2]){
            pox.push(x+1), poy.push(y+2), moves.push(moves.front()+1), visited[x+1][y+2]=1;
        }
        if((mat[x+2][y+1]=='.' || mat[x+2][y+1]=='H') && !visited[x+2][y+1]){
            pox.push(x+2), poy.push(y+1), moves.push(moves.front()+1), visited[x+2][y+1]=1;
        }
        if((mat[x-1][y-2]=='.' || mat[x-1][y-2]=='H') && !visited[x-1][y-2]){
            pox.push(x-1), poy.push(y-2), moves.push(moves.front()+1), visited[x-1][y-2]=1;
        }
        if((mat[x-2][y-1]=='.' || mat[x-2][y-1]=='H') && !visited[x-2][y-1]){
            pox.push(x-2), poy.push(y-1), moves.push(moves.front()+1), visited[x-2][y-1]=1;
        }
        if((mat[x+1][y-2]=='.' || mat[x+1][y-2]=='H') && !visited[x+1][y-2]){
            pox.push(x+1), poy.push(y-2), moves.push(moves.front()+1), visited[x+1][y-2]=1;
        }
        if((mat[x+2][y-1]=='.' || mat[x+2][y-1]=='H') && !visited[x+2][y-1]){
            pox.push(x+2), poy.push(y-1), moves.push(moves.front()+1), visited[x+2][y-1]=1;
        }
        if((mat[x-1][y+2]=='.' || mat[x-1][y+2]=='H') && !visited[x-1][y+2]){
            pox.push(x-1), poy.push(y+2), moves.push(moves.front()+1), visited[x-1][y+2]=1;
        }
        if((mat[x-2][y+1]=='.' || mat[x-2][y+1]=='H') && !visited[x-2][y+1]){
            pox.push(x-2), poy.push(y+1), moves.push(moves.front()+1), visited[x-2][y+1]=1;
        }
        moves.pop();
        mo++;
    }
}

int main()
{
    int x, y, a, b;
    int i, j;
    
    cin >> x >> y;
    for(i=2;i<=y+1;i++){
        for(j=2;j<=x+1;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='K')
                a=i, b=j;
        }
    }
    
    bfs(a, b);
    
    return 0;
}
