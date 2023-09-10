public class itemList {

    private static final int MAX_SIZE = 100;
    private int numOfItems, currentSlotInItems, currentSlotInShoppingCart;
    private Artigo[] items, shoppingCart;
    private int numOfItemsInShoppingCart;

    public itemList(int size) {

        numOfItems = size;
        currentSlotInItems = 0;
        numOfItemsInShoppingCart = 0;
        items = new Artigo[numOfItems];
    }

    public int getPriceFromItem(int index) {

        return items[index].getCost();
    }

    public void addItemToList(String name, int price) {

        items[currentSlotInItems] = new Artigo(name, price);
        currentSlotInItems++;

    }

    public String getLabelFromItem(int index) {
        return items[index].getItemLabel();
    }

    public int getItemCostByIndex(int index) {
        return items[index].getCost();
    }

    public Artigo acessItemInMainListNo(int index) {
        return items[index];
    }

    public int lookForMostExpensiveItem() {

        int i, maxValue, expensive;
        for (i = 0, maxValue = 0, expensive = 0; i < numOfItems; i++) {
            if (items[i].isBought()) {
                if (items[i].getCost() > maxValue) {

                    maxValue = items[i].getCost();
                    expensive = i;
                } else {

                }
            } else {
            }
        }
        return expensive;
    }

    public int[] buyItems(Coupon vale) {

        int[] output = new int[2];
        int sum = 0;
        for (int i = 0; i < numOfItems; i++) {

            if (items[i].getCost() <= vale.getCouponValue()) {

                vale.deductValue(items[i].getCost());
                sum += items[i].getCost();
                numOfItemsInShoppingCart++;
                items[i].setToBought();
            } else {

            }
        }
        output[0] = sum;
        output[1] = vale.getCouponValue();
        this.writeReceit();
        return output;
    }

    private void writeReceit() {

        shoppingCart = new Artigo[numOfItemsInShoppingCart];
        for (int i = 0; i < numOfItems; i++) {
            if (items[i].isBought()) {
                shoppingCart[currentSlotInShoppingCart] = new Artigo(items[i].getItemLabel(), items[i].getCost());
                currentSlotInShoppingCart++;
            }
        }

    }
    public int countBoughtItems() {

        return this.numOfItemsInShoppingCart;
    }
    /*Nota: "No" no nome do metodo e abreviatura para numero. le-se: aceder ao item comprado numero.... */
    public Artigo acessBoughtItemNo(int index) {
        return shoppingCart[index];
    }

    public void LeBubbleSortOfItemes() {
        for (int i = 0; i < this.countBoughtItems(); i++) {

            for (int j = 0; j < this.countBoughtItems() - 1-i; j++) {
                if (shoppingCart[j].CompareTo(shoppingCart[j + 1]) < 0) {
                    swapItems(j, j + 1);
                } 
                else if (shoppingCart[j].CompareTo(shoppingCart[j + 1]) == 0) {
                    if (shoppingCart[j].getItemLabel().compareTo(shoppingCart[j + 1].getItemLabel()) > 0) {
                        swapItems(j, j + 1);
                    }
                } else {

                }
            }
        }
    }
    private void swapItems(int firstIndex, int secondIndex) {

        Artigo tmp = new Artigo("tmp", 0);
        tmp = shoppingCart[firstIndex];
        shoppingCart[firstIndex] = shoppingCart[secondIndex];
        shoppingCart[secondIndex] = tmp;

    }

}
