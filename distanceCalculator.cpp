#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double L1_norm(vector<double> p1, vector<double> p2)
{
    double result=0;
    for(int i=0; i<p1.size(); i++)
    {
        result = result + abs(p1.at(i) - p2.at(i));
    }
    
    return result;
}

double L2_norm(vector<double> p1, vector<double> p2)
{
    double result=0;
    for(int i=0; i<p1.size(); i++)
    {
        result = result + pow(p1.at(i) - p2.at(i), 2);
    }
    
    return sqrt(result);
}

double Linf_norm(vector<double> p1, vector<double> p2)
{
    vector<double> values;
    for(int i=0; i<p1.size(); i++)
    {
        values.push_back(abs(p1.at(i) - p2.at(i)));
    }
    
    double maxValue=values.at(0);
    for(int i=1; i<values.size(); i++)
    {
        if(maxValue < values.at(i))
            maxValue = values.at(i);
    }
    
    return maxValue;
}

int main()
{
    int numOfPoints;
    cout << "How many data points do you want to insert: ";
    cin >> numOfPoints;
    
    int numOfDimensions; 
    cout << "How many dimensions does each data point have: ";
    cin >> numOfDimensions;
    
    cout <<"Please enter " << numOfPoints <<" data points, which have " << numOfDimensions << " dimensions:" << endl;
    
    vector<vector<double>> points(numOfPoints, vector<double>(numOfDimensions,0));
    
    for(int i=0; i<numOfPoints; i++)
    {
        cout << "Enter coordinates of point X" << i+1 << ":" << endl;;
        for(int j=0; j<numOfDimensions; j++)
        {
            double coordinate;
            cin >> coordinate;
            points.at(i).at(j) = coordinate;
        }
    }
    
    int distMeasure;
    while(true)
    {
        cout << "Choose diatnce measure: 1 = L1-norm, 2 = L2-norm, 3 = Linf-norm:" << endl;
        cin >> distMeasure;
    
        vector<vector<double>> distances(numOfPoints, vector<double>(numOfPoints,0));
    
        for(int k=0; k<numOfPoints; k++)
        {
            for(int m=k+1; m<numOfPoints; m++)
            {
                if(distMeasure==1)
                {
                    cout << "L1(X"<<k+1<<", X"<<m+1<<")=";
                    distances.at(k).at(m) = L1_norm(points.at(k), points.at(m));
                }
                else if(distMeasure==2)
                {
                    cout << "L2(X"<<k+1<<", X"<<m+1<<")=";
                    distances.at(k).at(m) = L2_norm(points.at(k), points.at(m));
                }
                else if(distMeasure==3)
                {
                    cout << "Linf(X"<<k+1<<", X"<<m+1<<")=";
                    distances.at(k).at(m) = Linf_norm(points.at(k), points.at(m));
                }
                //as the resulting matrix is symmetric:
                distances.at(m).at(k) = distances.at(k).at(m);
                cout <<  distances.at(k).at(m) << endl;
            }
        }
    
        int showAsMatrix;
        cout << "Insert: 1 - to show result in matrix form: ";
        cin >> showAsMatrix;
    
        if(showAsMatrix == 1)
        {
            for(int i=0; i<distances.size(); i++)
            {
                for(int j=0; j<distances.size(); j++)
                {
                    cout << distances.at(i).at(j)<<"    ";
                }
                cout << endl;
            }
        }
    }

   return 0;
}


