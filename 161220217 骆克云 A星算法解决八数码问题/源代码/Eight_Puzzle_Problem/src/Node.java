import java.util.Comparator;
import java.util.Scanner;
import java.util.Vector;
import java.lang.Math;

class MyNameComp implements Comparator<Node>{ 
    @Override
    public int compare(Node n1, Node n2) {
    	int val = n1.compareEqual(n2);
        return val;
    }
}  
 
class MyFvalueComp implements Comparator<Node>{
    @Override
    public int compare(Node n1, Node n2) {
        if(n1.getFvalue() > n2.getFvalue()){
            return 1;
        }
        else if(n1.getFvalue() < n2.getFvalue()){
            return -1;
        }
        return n1.compareEqual(n2);
    }
}


public class Node {
	int[][] puzzle = new int[3][3];
	int fvalue;
	public int getFvalue() {
		return fvalue;
	}

	public void setFvalue(int fvalue) {
		this.fvalue = fvalue;
	}

	int gvalue;
	int hvalue;
	Node pnode;
	
	//Ĭ�Ϲ��캯��
	public Node(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				puzzle[i][j]=-1;
			}
		}
		fvalue = 0;
		gvalue = 0;
		hvalue=0;
		pnode = null;
	}
	
	//���������Ĺ��캯��
	public Node(int[][] check){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				puzzle[i][j]=check[i][j];
			}
			fvalue = 0;
			gvalue = 0;
			hvalue=0;
			pnode = null;
		}
	}
	
	//��ȡ�ƶ�������Ľ��
	Node getLeft(int heuristic, Node goal){
		Node temp = new Node();
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(puzzle[i][j]==0){
					if(j==0) return null;
					temp.puzzle[i][j-1] = puzzle[i][j];
					temp.puzzle[i][j] = puzzle[i][j-1];
				}
				else{
					temp.puzzle[i][j]=puzzle[i][j];
				}
			}
		}
		temp.gvalue = gvalue + 1;
		temp.hvalue=temp.hfunc(heuristic,goal);
		temp.fvalue = temp.gvalue+temp.hvalue;
		temp.pnode = this;
		return temp;
	}
	
	//��ȡ�ƶ�������Ľ��
	Node getRight(int heuristic, Node goal){
		Node temp = new Node();
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(puzzle[i][j]==0){
					if(j==2) return null;
					temp.puzzle[i][j+1] = puzzle[i][j];
					temp.puzzle[i][j] = puzzle[i][j+1];
					j++;
				}
				else{
					temp.puzzle[i][j]=puzzle[i][j];
				}
			}
		}
		temp.gvalue = gvalue + 1;
		temp.hvalue=temp.hfunc(heuristic,goal);
		temp.fvalue = temp.gvalue+temp.hvalue;
		temp.pnode = this;
		return temp;
	}
	
	//��ȡ�ƶ�������Ľ��
	Node getUp(int heuristic, Node goal){
		Node temp = new Node();
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(puzzle[i][j]==0){
					if(i==0) return null;
					temp.puzzle[i-1][j] = puzzle[i][j];
					temp.puzzle[i][j] = puzzle[i-1][j];
				}
				else{
					temp.puzzle[i][j]=puzzle[i][j];
				}
			}
		}
		temp.gvalue = gvalue + 1;
		temp.hvalue=temp.hfunc(heuristic,goal);
		temp.fvalue = temp.gvalue+temp.hvalue;
		temp.pnode = this;
		return temp;
	}
	
	//��ȡ�ƶ�������Ľ��
	Node getDown(int heuristic, Node goal){
		Node temp = new Node();
		for(int j=0;j<3;j++){
			for(int i=0;i<3;i++){
				if(puzzle[i][j]==0){
					if(i==2) return null;
					temp.puzzle[i+1][j] = puzzle[i][j];
					temp.puzzle[i][j] = puzzle[i+1][j];
					i++;
				}
				else{
					temp.puzzle[i][j]=puzzle[i][j];
				}
			}
		}
		temp.gvalue = gvalue + 1;
		temp.hvalue=temp.hfunc(heuristic,goal);
		temp.fvalue = temp.gvalue+temp.hvalue;
		temp.pnode = this;
		return temp;
	}
	
	//�����������
	void printNode(){
		System.out.println("\n��ӡ��㣺");
		System.out.println(puzzle[0][0]+" "+puzzle[0][1]+" "+puzzle[0][2]);
		System.out.println(puzzle[1][0]+" "+puzzle[1][1]+" "+puzzle[1][2]);
		System.out.println(puzzle[2][0]+" "+puzzle[2][1]+" "+puzzle[2][2]);
		System.out.println("f(n)="+fvalue);
		System.out.println("g(n)= "+gvalue);
		System.out.println("h(n)="+hvalue);
	}
	
	//��ȡ�ھӽ��
	Vector<Node> getAllNeighbours(int heuristic,Node goal){
		Vector<Node> allNeighbours = new Vector<Node>();
		
		Node leftNode = this.getLeft(heuristic,goal);
		if(leftNode!=null)
			allNeighbours.add(leftNode);
		Node rightNode = this.getRight(heuristic,goal);
		if(rightNode!=null)
			allNeighbours.add(rightNode);
		Node upNode = this.getUp(heuristic,goal);
		if(upNode!=null)
			allNeighbours.add(upNode);
		Node downNode = this.getDown(heuristic,goal);
		if(downNode!=null)
			allNeighbours.add(downNode);
		return allNeighbours;
	}
	
	//���Ƚ�
	int compareEqual(Node node){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(puzzle[i][j]<node.puzzle[i][j]){
					return -1;
				}
				if(puzzle[i][j]>node.puzzle[i][j]){
					return 1;
				}
			}
		}
		return 0;
	}
	
	//�����������
	public int hfunc(int heuristic, Node goal) {		
		int count=0;	
		//��Ŀ�����һ��λ�ò�ͬ�ͷ���1
		if(heuristic == 1){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(puzzle[i][j]!=goal.puzzle[i][j]) 
						return 1;
				}
			}
		}
		
		//������Ŀ�����λ�ò�ͬ��Ŀ
		else if(heuristic == 2){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(puzzle[i][j]==0) 
						continue;
					if(puzzle[i][j]!=goal.puzzle[i][j] ) 
						count++;
				}
			}
		}
		
		//�����پ���
		else if(heuristic ==3){
			int[] x = new int[8];
			int[] y = new int[8];
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(puzzle[i][j]==0) 
						continue;
					x[puzzle[i][j]-1] = i;
					y[puzzle[i][j]-1] = j;
				}
			}
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(goal.puzzle[i][j]==0) 
						continue;
					int row = x[goal.puzzle[i][j]-1];
					int column = y[goal.puzzle[i][j]-1];
					count = count + Math.abs(i-row)+Math.abs(j-column);
				}
			}
		}
		
		return count;
	}
	
	//����������
	int calculate(Node node){
		int[] sample=new int[8];
		int num=0;
		int index=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(node.puzzle[i][j]==0){
					index=1;
					continue;
				}
				sample[3*i+j-index]=node.puzzle[i][j];
			}
		}
		
		for(int i=0;i<8;i++){
			for(int j=i+1;j<8;j++){
				if(sample[j]<sample[i]) 
					num++;
			}
		}
		return num;
	}
	
	//�жϿɽ���
	public boolean checkReachibility(Node goal) {
		int srcnum = calculate(this);
		int goalnum = calculate(goal);
		System.out.println("Դ����������� "+srcnum);
		System.out.println("Ŀ������������ "+goalnum);
		if((srcnum-goalnum)%2==0) 
			return true;
		return false;
	}

	//ɨ������ʽ�㷨ѡ��
	public int takeHeuristic() {
		System.out.println("ѡ���㷨\n1 �������                      (h=1)\n"+
							"2 Ŀ����������        (h=��(��Ŀ���㲻ͬ��λ����))\n"+
							"3 �����پ���                 (h=��(|src.x-goal.x|+|src.y-goal.y|))\n");
		@SuppressWarnings("resource")
		int h = new Scanner(System.in).nextInt();
		return h;
	}
	
}