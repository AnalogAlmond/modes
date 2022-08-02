#include<bits/stdc++.h>
#include<random>

using namespace std;

#define MODES 7
#define COMBINATIONS 84

void userInput(string& key);

int main(){
    string keys[] = {"c", "g", "d", "a", "e", "b", "f#", "c#", "ab", "eb", "bb", "f"};
    string mode[] = {"ionian", "dorian", "phrygian", "lydian", "mixolydian", "aeolian", "locrian"};
    int used[MODES];
    string usedcombos[COMBINATIONS];
//    string command;
    string key;
    int scales;

    srand(time(0));//takes the current time as a seed
    int r = rand()%7;//generates a random number between 0 and 6
    int rkey = rand()%12;//between 0 and 11
    
//    system("mocp --server");
    userInput(key);
    
    //if the user only wants one key:
    if(find(begin(keys), end(keys), key)!=end(keys)){
        for(int i = 0; i < MODES; i++){
            used[i] = r;
            cout << mode[r] << '\n';
//            command = "mocp --enqueue tracks/" + key + '/' + mode[r] + ".mp3";//command to get the file into the queue
//            system(command.c_str());//turns it into a constant char* and runs the command
            if(i == 6) break;
            while(find(begin(used), end(used), r)!=end(used)){
                r = rand()%7;
            }
        }
    }
    //if the user wants multiple keys:
    else if(strcmp(key.c_str(), "all") == 0){
        cout << "how many scales would you like in total? max=" << COMBINATIONS << '\n';
        cin >> scales;
        if (scales > COMBINATIONS) return 1;
        for(int i = 0; i < scales; i++){
           usedcombos[i]=keys[rkey] + "/" + mode[r];
           cout << usedcombos[i] << '\n';
//           command = "mocp --enqueue tracks/" + usedcombos[i] + ".mp3";//command to get the file into the queue
//           system(command.c_str());//turns it into a constant char* and runs the command
           if(i == (scales-1)) break;
           while(find(begin(usedcombos), end(usedcombos), keys[rkey] + "/" + mode[r])!=end(usedcombos)){
                r = rand()%7;
                rkey = rand()%12;
           }
       }
    }
    else{
        return 1;
    }
    
//    system("mocp --play");//starts the playlist
    return 0;
}


void userInput(string& key){
    cout << "what key would you like?\n";
    cout << "c, g, d, a, e, b, f#, c#, ab, eb, bb, f\n";
    cout << "type 'all' for all keys\n";
    cin >> key;
}
