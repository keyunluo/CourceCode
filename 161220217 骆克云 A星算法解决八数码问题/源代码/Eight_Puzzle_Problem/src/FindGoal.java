import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;
import java.util.Vector;

public class FindGoal {
	
	void findGoal(Node src, Node goal,int heuristic){
		OpenList ol = new OpenList();
		ClosedList cl = new ClosedList();
		ol.add(src);
		Boolean reachability = false;
		while(!ol.isEmpty()){			
			Node node = ol.getFirst();
			ol.remove(node);
			cl.add(node);
			if(node.compareEqual(goal)==0){
				System.out.println("找到最优路径，该路径为：");
				reachability = true;
				int pathLength = node.gvalue;
			
				List<Node> tmpNodes=new ArrayList<Node>();
				while(node.pnode!=null){
					tmpNodes.add(0, node);
					node = node.pnode;
				}
				
				for(int i=0;i<tmpNodes.size();i++){
					System.out.printf("\n第%d步：", i+1);
					tmpNodes.get(i).printNode();
				}
				
				System.out.println("\n路径长度： "+pathLength);
				break;
			}
			else{
				Vector<Node> neighbours = node.getAllNeighbours(heuristic,goal);
				Enumeration<Node> vEnum = neighbours.elements();
				while(vEnum.hasMoreElements()){
					Node element = vEnum.nextElement();
					if(cl.putNode(element)) 
						continue;
					ol.putNode(element);
				}
			}
		}
		if(!reachability) 
			System.out.println("解路径不存在！");
		System.out.println("Open 表大小： "+ol.getSize());
		System.out.println("Closed 表大小： "+cl.getSize());
		
		return;
	}
	
}
	
	
