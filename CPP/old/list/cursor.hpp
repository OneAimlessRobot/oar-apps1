class cursor
{
    int pos;
    task* array;
    int maxpos;

public:
    cursor(int arraysize)
    {

        pos = 0;
        maxpos = arraysize;
        array=new task[maxpos];
        
    }
    int getPos()
    {
        return pos;
    }

    int move(int distance)
    {
        int res=0;
        if (!(pos + distance < 0) && !(pos + distance >= maxpos))
        {

            pos += distance;
        }
        else
        {
            res=1;
        }
        return res;
    }
};