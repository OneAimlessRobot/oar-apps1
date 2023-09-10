public class Colection {

    private static final int DEFAULT_SIZE = 100;
    private Record[] collection;
    private int nextSlot, sizeOfCollection, recordCount;

    public Colection() {
        sizeOfCollection = DEFAULT_SIZE;
        nextSlot = 0;
        recordCount = 0;
        collection = new Record[sizeOfCollection];
    }

    public void addRecord(String author, String title, int year) {

        if (isFull()) {
            grow();
        }

        collection[nextSlot++] = new Record(author, title, year);
        recordCount++;
    }

    public boolean isFull() {

        return nextSlot == sizeOfCollection;
    }

    public void grow() {

        int oldsize = sizeOfCollection;

        Record[] auxList = new Record[sizeOfCollection *= 2];

        for (int i = 0; i < oldsize; i++) {

            auxList[i] = collection[i];

        }

        collection = auxList;
        }

    public void sortThisList() {

        for (int i = 0; i < recordCount - 1; i++) {

            for (int j = 0; j < recordCount - i; j++) {

                if (collection[j].compareRecords(collection[j + 1]) > 0) {

                    Record aux = collection[j];
                    collection[j] = collection[j + 1];
                    collection[j + 1] = aux;

                } else {

                }

            }
        }

    }

    public void sort(Record[] sample, int n) {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n - i - 1; j++) {

                if (sample[j].compareRecords(sample[j + 1]) > 0) {

                    Record aux = sample[j];
                    sample[j] = sample[j + 1];
                    sample[j + 1] = aux;

                } else {

                }

            }
        }

    }

    public ColectionIterator iterator() {

        return new ColectionIterator(recordCount, collection);

    }

    public ColectionIterator sortedIterator() {

        Record[] aux = new Record[recordCount];

        for (int i = 0; i < recordCount; i++) {

            aux[i] = this.collection[i];

        }

        sort(aux, recordCount);
        return new ColectionIterator(recordCount, aux);
    }

    public ColectionIterator sortedAndFilteredIterator(String c) {

        Record[] aux = new Record[recordCount];
        int j = 0;
        for (int i = 0; i < recordCount; i++) {

            if (condition(c, collection[i])) {

                aux[j++] = collection[i];
            }

        }

        sort(aux, j);
        return new ColectionIterator(j, aux);
    }

    public boolean condition(String c, Record r) {

        return r.getAuthor().equals(c);
    }

    public FilteredIterator filteredIterator(String c) {

        return new FilteredIterator(collection, recordCount, c);

    }

    public void removeRecord(String author, String title) {

        Record[] aux = new Record[recordCount];

        int adequate = 0;
        for (int i = 0; i < recordCount; i++) {

            if (collection[i].getAuthor().equals(author) && collection[i].getTitle().equals(title)) {

                for (int j = i; j < recordCount - 1; j++) {

                    collection[j] = collection[j + 1];
                }
                adequate = 1;

            } else {

            }
        }

        if (adequate == 1) {

            for (int i = 0; i < recordCount; i++) {

                aux[i] = collection[i];
            }
        }

        collection = aux;
        recordCount--;
        nextSlot--;

    }

    public int searchForAlbum(String author, String title) {

        int result = 0;

        for (int i = 0; i < recordCount; i++) {

            if (collection[i].getAuthor().equals(author) && collection[i].getTitle().equals(title)) {

                result = 1;

            } else {

            }
        }
        return result;
    }

    public Record searchForAlbumAndReturn(String author, String title) {

        Record result = null;

        for (int i = 0; i < recordCount; i++) {

            if (collection[i].getAuthor().equals(author) && collection[i].getTitle().equals(title)) {

                result = collection[i];

            } else {

            }
        }
        return result;
    }

    public int getCollectionSize() {
        return this.recordCount;
    }

}
