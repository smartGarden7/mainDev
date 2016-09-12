extern void checkFailures(int minutesPassed, bool irrigationFail) {
  print_displa("Starting initialization test");
  if(minutesPassed != 180) {
    int minutesLeft = 180 - minutesPassed;
    print_display("Irrigation Error.",size,color,x,y);
    printint_display(minutesLeft,size,color,x,y)
    print_display("minutes left. Re-starting irrigation process.",size,color,x,y)
    irrigateMinutes(minutesLeft);
  }
  else if(irrigationFail true) {
    print_display("Something is wrong with the water/valve, fix the problem and click the button.")
    waitForFix(); // System is blocked until user pushed the button.
  }
  else {
    print_display("Succesfully passed initialization test.")
  }
}
