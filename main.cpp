#include "header.h"

int main()
{
    /* ===========================================================
    |SIMULATED ANNEALING |
    |--------------------*
    |Variable y  = Neighbor solution of x
    |Variable b  = Best-so-far Solution
    |Variable T  = Temperature (Annealing Schedule)
    |Variable E  = Energy from evaluated solution
    |Variable dE = Delta Energy = Ey - Ex
    |
    |The result of this program will be recorded into a log file
    |Made By: Hardiyan Ichsan Gunawan (HaRuDe)
    =============================================================*/
    double y1, y2, b1, b2;
    int i = 1;
    double T, Eb, Ex, Ey, dE;
    ofstream logfile;           // Make a file variable
    logfile.open("log.txt");    // Create a file for logging

    // Initialization for rand()
    srand(time(0));
    srand(rand());

    // Initialization value
    double x1;
    x1 = randomizer();
    double x2;
    x2 = randomizer();

    b1 = x1;
    b2 = x2;
    Eb = calculate(b1,b2);

    cout<<"Initial x1 : "<< b1 <<endl<<"Initial x2 : "<<b2<<endl;
    cout<<"E Best-so-Far : "<<Eb<<endl;

    // Input Initial T Value
    cout<<"Input the maximum T value : ";
    cin>>T;
    cout<<"Press any key to start...\n";
    getch();
    cout<<"[";
    while (T > 0.0000001){
        logfile<<"Iteration-"<<i<<" :"<<endl;
        y1 = neighbour(x1); // Create a neighbor of the solution from x
        y2 = neighbour(x2);
        logfile<<"value y1,y2 = "<<y1<<", "<<y2<<endl;
        logfile<<"value x1,x2 = "<<x1<<", "<<x2<<endl;
        Ey = calculate(y1,y2);  // Evaluate solution y
        logfile<<"value Ey = "<<Ey<<endl;
        Ex = calculate(x1,x2);  // Evaluate solution x
        logfile<<"value Ex = "<<Ex<<endl;
        dE = Ey - Ex;  // Calculate delta E
        logfile<<"value dE = "<<dE<<endl;
        logfile<<"current Eb = "<<Eb<<endl;
        logfile<<"==============================="<<endl;

        if (dE < 0){ // Check if delta E less than 0
            x1 = y1;
            x2 = y2;
            if (Ey < Eb){ // Check if new E less than E best-so-far
                b1 = x1;  // if true, then change the solutions
                b2 = x2;
                Eb = Ey;
            }
        } else {
            double r = (double)randr();               // Create another random solution range [0,1]
            double eks = exp(-dE/T);
            if (r < eks){                  // Check if the new random solution (r) is less than exponent(-delta E / T)
                x1 = y1;                   // The less T value, the more difficult to accept the bad move
                x2 = y2;
                logfile<<"nilai r : "<<r<<endl;

                logfile<<"nilai exp : "<<eks<<endl;
                logfile<<"^=============================^"<<endl;
            }
        }
        cout<<"=";
        i++;
        T = (T - 0.1) * 0.99999; // Decrement T by 0.1 and multiply 0.99999
    }
    cout<<"]\n";
    cout<<endl<<"Final Solution x1, x2 : "<<x1<<", "<<x2<<endl;
    cout<<"Final Solution y1, y2 : "<<y1<<", "<<y2<<endl;
    cout<<"Final Solution b1, b2 : "<<b1<<", "<<b2<<endl;
    cout<<"Final Solution Ex : "<<Ex<<endl;
    cout<<"Final Solution Ey : "<<Ey<<endl;
    cout<<"Final Solution Eb : "<<Eb<<endl;
    cout<<"The result each iteration is recorded into logfile.txt";

    // Printed into file
    logfile<<endl<<"Final Solution x1, x2 : "<<x1<<", "<<x2<<endl;
    logfile<<"Final Solution y1, y2 : "<<y1<<", "<<y2<<endl;
    logfile<<"Final Solution b1, b2 : "<<b1<<", "<<b2<<endl;
    logfile<<"Final Solution Ex : "<<Ex<<endl;
    logfile<<"Final Solution Ey : "<<Ey<<endl;
    logfile<<"Final Solution Eb : "<<Eb<<endl;
    getch();
    return 0;
}
