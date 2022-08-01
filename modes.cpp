#include<bits/stdc++.h>
#include<random>

using namespace std;

int main(){
    string key = "c";
    string mode[] = {"ionian", "dorian", "phrygian", "lydian", "mixolydian", "aeolian", "locrian"};

    srand(time(0));//takes the current time as a seed
    int r = (rand()%7);//generates a random number between 0 and 6
    int used[7];
    string file;
    system("mocp --server");
    
    for(int i = 0; i < 7; i++){
        used[i] = r;
        cout << mode[r] << '\n';
        file = "mocp --enqueue " + key + '/' + mode[r] + ".mp3";//command to get the file into the queue
        system(file.c_str());//turns it into a constant char* and runs the command
        if(i == 6) break;
        while(find(begin(used), end(used), r)!=end(used)){
            r = (rand()%7);
        }
    }
    system("mocp --play");//starts the playlist
    return 0;
}
