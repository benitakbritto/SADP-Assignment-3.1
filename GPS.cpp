/*
 * This file is used to check the GPS
 * connectivity
 */
#include<iostream>
#include<time.h>
using namespace std;

//class Gps : public iGps
class Gps
{
  public:
  int getMobileNetwork();
  void isGpsWeak();

};
/*
 * Used to get the number of bars/strength in mobile network
 * Maximum number of bars is five
 * @return int bar_number the number of bars in the network
 */
int Gps :: getMobileNetwork()
{
    /*
     * generating the strength/ bar number randomly
     */
    srand(time(NULL));
    int bar_number = (rand() %5);

    return bar_number;
}

/*
 * used to check if the network is weak
 * a weak network is characterised by 0 or 1 bar
 * @return bool true if GPS is weak
 */
void Gps :: isGpsWeak()
{
    /*
     * calls functions getMobileNetwork() to determine
     * the number of bars/strength
     */
    if(getMobileNetwork() == 0 || getMobileNetwork() == 1)
    {
        /*
         * network is weak
         * and hence, it tries to check the connectivity again
         */
        cout<<"GPS connectivity is weak"<<endl;
        cout<<"Reconnecting"<<endl;
        /*
         * connectivity is still weak, then exit the application
         * else, continue with the application
         */
        if(getMobileNetwork() == 0 || getMobileNetwork() == 1)
        {
            cout<<"Exiting application"<<endl;
            exit(0);
        }
      //  return true;
    }
    //return false;
}
