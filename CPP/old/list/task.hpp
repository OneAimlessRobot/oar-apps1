using namespace std;
class task
{
    const static int DONE = 1;
    const static int INCOMPLETE = 0;
    string desc;
    int status;


public:

    task()
    {
        desc="No description specified";
        status = INCOMPLETE;
    }
    task(string description){

        desc=description;


    }
    char setDone()
    {
        char result;
        if(!isComplete()){

        status = DONE;
        result='\a';
        }
        return result;
    }
    bool isComplete(){
        return status==DONE;
    }
    int getStatus(){
        return status;
    }
    string getDesc(){
        return desc;
    }
};