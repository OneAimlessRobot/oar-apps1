

public class ByteVec{

private int size,nextSlotToFill,nextSlotToReturn;
private byte[] fileInMemory;  

ByteVec(){

this.size=100;
fileInMemory=new byte[size];
nextSlotToFill=0;
nextSlotToReturn=0;

}

public void insertByte(byte next){
if(isFull()){
grow();
fileInMemory[nextSlotToFill++]=next;
}
else{
fileInMemory[nextSlotToFill++]=next;
}
}

public boolean hasNext(){

return nextSlotToReturn<nextSlotToFill;
}


public boolean isFull(){

return nextSlotToFill==size;
}

public byte getNextByte(){

return fileInMemory[nextSlotToReturn++];
}

public void grow(){

byte[] tmp =new byte[size*2];


for(int i=0;i<size;i++){

tmp[i]=fileInMemory[i];



}
fileInMemory=tmp;
size*=2;

}



public int getFillSlot(){
return nextSlotToFill;
}

public int getReturnSlot(){
return nextSlotToReturn;
}




}
