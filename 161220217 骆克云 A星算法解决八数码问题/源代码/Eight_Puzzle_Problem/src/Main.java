public class Main {
	public static void main(String[] args){
		int[][] src_matrix = {{1,3,5},{0,7,4},{6,2,8}};
//		int [][] src_matrix = {{1,3,5},{0,7,4},{6,8,2}};
//		int [][] goal_matrix = {{1,2,3},{4,5,6},{7,8,0}};
		int[][] goal_matrix = {{1,2,3},{4,5,6},{7,8,0}};
		Node src = new Node(src_matrix);
		Node goal = new Node(goal_matrix );
		FindGoal findGoal=new FindGoal();
		int heuristic = src.takeHeuristic();
		if(src.checkReachibility(goal)) 
			findGoal.findGoal(src,goal,heuristic);
		else 
			System.out.println("�޽⣡");
	}
}
