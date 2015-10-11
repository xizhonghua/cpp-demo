public class Sample1
{
    public native double evaluate(double[] config);

    public static void main(String[] args)
    {
        // load library
        System.loadLibrary("evaluation");
        // create new instance
        Sample1 sample = new Sample1();
        // invoke native (c/c++) method
        double value = sample.evaluate(new double[]{2.0, 3.0, -4.0, 2.8, 1.2});

        System.out.println("evaluation result = " + value);
    }
}