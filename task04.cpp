#include <iostream>
#include <ctime>
using namespace std;
int main(){
    
    int array[100][100];

    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            array[i][j]=0;
        }
    }

	clock_t time_req;

    srand(time(NULL));
    array[rand()%100][rand()%100]=1;

    //======================
	// Using direction search
	time_req = clock();
	
    for(int i=0; i <100; i++){
        for (int j=0; j<100; j++){
            if (array[i][j]==1){
                cout << "===========\n";
                cout << "[" << i+1 << "][" << j+1 << "]=" << array[i][j] << endl;
            }
        }
    }

	cout << "Using direction search, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;

	//=====================
	// using random search

	time_req = clock();

	int x,y,flag;

    while(true){	
	    x = rand()%100;
	    y = rand()%100;
				
	    if(array[x][y]==1){
			flag =1;
			break;					
		}
	    else continue;
    }
	cout << "using random search, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
     
    return 0;
}