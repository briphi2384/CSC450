public class PortProjectMod8 {
	
	private static final Object lock = new Object(); //lock object for synchronization
	private static boolean isCountUpDone = false; //flag

	public static void main(String[] args) {
		//Create and start counting up thread
		Thread countUpThread = new Thread(new CountUpTask());
		countUpThread.start();
		
		//Create and start counting down thread
		Thread countDownThread = new Thread(new CountDownTask());
		countDownThread.start();
		
		//Wait for threads to finish
		try {
			countUpThread.join();
			countDownThread.join();
		}catch (InterruptedException e) {
			e.printStackTrace();
		}

	}//end main

	static class CountUpTask implements Runnable {
		@Override
		public void run() {
			synchronized (lock) {
				for(int i =0; i <= 20; i++) {
					System.out.println("Counting up: " + i);
				}//end for
				
				//set flag and notify waiting thread
				isCountUpDone = true;
				lock.notifyAll();
				
			}//end sync
		}//end run
	}//end countuptask class
	
	static class CountDownTask implements Runnable {
		@Override
		public void run() {
			synchronized (lock) {
				//wait until countUpTask is done
				while (!isCountUpDone) {
					try {
						lock.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}//end try/catch
				}//end while
				
				//Start counting down when notified
				for (int i = 20; i >= 0; i--) {
					System.out.println("Counting down: " + i);
				}//end for
			}//end sync
		}//end run
	}//end countdowntask class	
}//end class
