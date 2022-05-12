#include <iostream>
#include <ctime>
using namespace std;

int main(){
    int n=1000;
    int array[n][n];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            array[i][j]=0;
        }
    }

	clock_t timer;
    clock_t timer2;
    clock_t timer3;
    clock_t timer4;



    srand(time(NULL));
    array[rand()%n][rand()%n]=1;

    //======================
	// Using direction search
	timer = clock();
	
    for(int i=0; i <n; i++){
        for (int j=0; j<n; j++){
            if (array[i][j]==1){
                cout << "===========\n";
                cout << "[" << i+1 << "][" << j+1 << "]=" << array[i][j] << endl;
            }
        }
    }

	timer2 = clock();

	cout << "Using direction search, it took " << ((float)timer2/CLOCKS_PER_SEC) - ((float)timer/CLOCKS_PER_SEC) << " seconds" << endl;

	//=====================
	// using random search

	timer3 = clock();

	int x,y;

    while(true){	
	    x = rand()%n;
	    y = rand()%n;

	    if(array[x][y]==1){
			break;					
		}
	    else continue;
    }

    timer4 = clock();

	cout << "using random search, it took " << ((float)timer4/CLOCKS_PER_SEC) - ((float)timer3/CLOCKS_PER_SEC) << " seconds" << endl;
     
    return 0;
}