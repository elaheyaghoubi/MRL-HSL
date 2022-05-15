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

	clock_t timer_linear1;
    clock_t timer_linear2;
    clock_t timer_random1;
    clock_t timer_random2;

    srand(time(NULL));
    array[rand()%n][rand()%n]=1;

    //======================
	// Using direction search
	timer_linear1 = clock();
	
    for(int i=0; i <n; i++){
        for (int j=0; j<n; j++){
            if (array[i][j]==1){
                cout << "===========\n";
                cout << "[" << i+1 << "][" << j+1 << "]=" << array[i][j] << endl;
            }
        }
    }

	timer_linear2 = clock();
    double direction_time = ((float)timer_linear2/CLOCKS_PER_SEC) - ((float)timer_linear1/CLOCKS_PER_SEC);
	cout << "Using direction search, it took " << direction_time<< " seconds" << endl;

	//=====================
	// using random search

	timer_random1 = clock();

	int x,y;

    while(true){	
	    x = rand()%n;
	    y = rand()%n;

	    if(array[x][y]==1){
			break;					
		}
	    else continue;
    }

    timer_random2 = clock();
    double random_time=((float)timer_random2/CLOCKS_PER_SEC) - ((float)timer_random1/CLOCKS_PER_SEC);
	cout << "using random search, it took " << random_time << " seconds\n" << endl;
    
    if (random_time > direction_time){
        cout << "================================\n";
        cout << "random algorithm takes more time\n";
    }
    else{
        cout << "================================\n";
        cout << "direction algorithm takes more time";
    }
    return 0;
}