#include<iostream>
#define rep(i,a,b) for(int i=a;i<=b;++i) // for convenience
#define REP(i,a,b) for(int i=a;i>=b;--i)
using namespace std;

const int dx[]={-1, 0, 1, 0};
const int dy[]={ 0, 1, 0,-1};
const int N=52;

// size of problem
int n;
// game problem matrix
int a[N][N];
// ci[i][v]: number of v in i-th row
int ci[N][3];
// cj[j][v]: number of v in j-th col
int cj[N][3];
// have solve the game successfully?
bool success;
// is (x,y) inside the board?
int inside(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=n;
}
// can put color v at (x,y)?
int can_place(int x,int y,int v){
	// 1. ensure there're same count of color inside each row and col
	if(ci[x][v]>=n/2||cj[y][v]>=n/2)return 0;
	
	// if 4 directions already have 2 blocks lining up with the same color
	rep(o,0,3){
		int c=0;
		REP(s,2,1){
			int x2=x+dx[o]*s,y2=y+dy[o]*s;
			if(inside(x2,y2)&&a[x2][y2]==v){
				++c;
			}else break;
		}
		if(c==2)return 0;
	}
	// if 2 opposite directions both have 1 block with the same color
	rep(o,0,1){
		int c=0;
		for(int s=-1;s<=1;s+=2){
			int x2=x+dx[o]*s,y2=y+dy[o]*s;
			if(inside(x2,y2)&&a[x2][y2]==v){
				++c;
			}else break;
		}
		if(c==2)return 0;
	}
	return 1;
}
// is 2 rows have the same content? 
int same_row(int i1,int i2){
	rep(j,1,n)if(a[i1][j]!=a[i2][j])return 0;
	return 1;
}
// is 2 cols have the same content? 
int same_col(int j1,int j2){
	rep(i,1,n)if(a[i][j1]!=a[i][j2])return 0;
	return 1;
}
void dfs(int x,int y){
	if(success)return;
	// if we have fill all the blocks
	if(x==n+1){
		// check whether have same rols or cols
		rep(i1,1,n)rep(i2,i1+1,n)if(same_row(i1,i2))return;
		rep(j1,1,n)rep(j2,j1+1,n)if(same_col(j1,j2))return;
		// check ok
		success=true;
		return;
	}
	// if (x,y) already have a color
	if(a[x][y]){
		if(y==n)dfs(x+1,1);
		else dfs(x,y+1);
		return;
	}
	rep(v,1,2){
		if(can_place(x,y,v)){
			// backtracking
			a[x][y]=v;
			++ci[x][v];
			++cj[y][v];
			if(y==n)dfs(x+1,1);
			else dfs(x,y+1);
			if(success)return;
			a[x][y]=0;
			--ci[x][v];
			--cj[y][v];
		}
	}
}
char present[3]={0,'-','|'};
int main(){
	// input
	cout<<"size of problem(4/6/8/12/customize):"<<endl;
	cin>>n;
	cout<<"initial matrix of game(0 for empty blocks, 1/2 for 2 types of blocks)):"<<endl;
	rep(i,1,n){
		rep(j,1,n){
			cin>>a[i][j];
			if(a[i][j]){
				// count the color in its row and col
				++ci[i][a[i][j]];
				++cj[j][a[i][j]];
			}
		}
	}

	// solve
	dfs(1,1);

	// output
	rep(i,1,n){
		rep(j,1,n){
			cout<<present[a[i][j]]<<' ';
		}
		cout<<endl;
	}
}