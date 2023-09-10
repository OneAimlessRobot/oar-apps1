public class Manager {

    private Colection kolection;

    public Manager(){

        kolection=new Colection();
    }

    public void sortColectionRemote(){

        kolection.sortThisList();
    }
    public FilteredIterator getFilteredIteratorRemote(String arg4It){

        return kolection.filteredIterator(arg4It);
    }

    public ColectionIterator gimmeASortedIterator(){
        return kolection.sortedIterator();
    }
    public ColectionIterator gimmeAnIterator(){
        return kolection.iterator();
    }
    public void addRecordRemote(String author,String title,int year){

        kolection.addRecord(author, title, year);
    }
    public int searchForAlbumRemote(String author,String title){

        return kolection.searchForAlbum(author, title);
    }
    public int getColectionSizeRemote(){

        return kolection.getCollectionSize();
    }
    public ColectionIterator superIterator(String c){

        return kolection.sortedAndFilteredIterator(c);


    }
    public void removeRecordRemote(String author,String title){

        kolection.removeRecord(author, title);
    }

    
}
