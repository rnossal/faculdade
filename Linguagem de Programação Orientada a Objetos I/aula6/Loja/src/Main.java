/**
 * Created by Rafael Nossal on 13/04/2017.
 */
public class Main {
	public static void main(String[] args) {
		Livro l1 = new Livro("aaaaaa", 111111, "cccccc");
		Livro l2 = new Livro("dddddd", 222222, "eeeeee");

		Cd c1 = new Cd("ffffff", 333333, 123);
		Cd c2 = new Cd("gggggg", 444444, 456);

		Dvd d1 = new Dvd("hhhhhh", 555555, 789);

		System.out.println(l1.toString() + "\n");
		System.out.println(l2.toString() + "\n");
		System.out.println(c1.toString() + "\n");
		System.out.println(c2.toString() + "\n");
		System.out.println(d1.toString() + "\n");
	}
}
