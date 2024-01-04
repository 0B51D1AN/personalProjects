public class Machine {

   public static void main( String[] args) {

 Drink drink1 = new Drink("Coke");
    Drink drink2 = new Drink("Sprite");
    Drink drink3 = new Drink("Blue Powerade", 2.75);
    Drink drink4 = new Drink("Guinness",6.25);


    drink1.refill();
    drink2.refill();
    drink3.refill();
    drink4.refill();


drink1.vend();
    drink1.vend();
    drink1.vend();
    drink1.vend();
    drink1.vend();
    drink1.vend();
    drink1.vend();
    drink1.vend();

 drink2.vend();
    drink2.vend();
    drink2.vend();
    drink2.vend();
    drink2.vend();
    drink2.vend();

drink3.vend();
    drink3.vend();


 drink4.vend();
    drink4.vend();
    drink4.vend();
    drink4.vend();
    drink4.vend();
    drink4.vend();
    drink4.vend();
    drink4.vend();
    drink4.vend();
    drink4.vend();
    drink4.vend();

int totalSold = drink1.drinksSold() + drink2.drinksSold() +
                    drink3.drinksSold() + drink4.drinksSold();

    double totalProfit = drink1.profit() + drink2.profit() +
                         drink3.profit() + drink4.profit();

    System.out.print("A Total of " + totalSold + " drinks were ");
    System.out.println("sold for a profit of $" + totalProfit);
    System.out.println();
    System.out.println( drink1.restockAmount() + " " + drink1.getDrinkName() + " needed to restock machine");
    System.out.println( drink2.restockAmount() + " " + drink2.getDrinkName() + " needed to restock machine");
    System.out.println( drink3.restockAmount() + " " + drink3.getDrinkName() + " needed to restock machine");
    System.out.println( drink4.restockAmount() + " " + drink4.getDrinkName() + " needed to restock machine");

      }
}
