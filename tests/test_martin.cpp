#include "auto_complete_graph/ACG.hpp"



void prior(AASS::acg::AutoCompleteGraph& acg){
	
	std::cout << "Making the prior" << std::endl;
	
	acg.printGraph();
	
	g2o::SE2 priorse20(1, 1, 0);
	g2o::VertexSE2Prior* prior0 = acg.addPriorLandmarkPose(priorse20);
	g2o::SE2 priorse21(2, 1, 0);
	g2o::VertexSE2Prior* prior1 = acg.addPriorLandmarkPose(priorse21);
	
	
	
	g2o::SE2 move(1, 0, DEG2RAD(90));
	
	g2o::EdgeSE2Prior_malcolm* wall0 = acg.addEdgePrior(move, prior0, prior1);
	
// 	assert(acg.getGraph().vertices().size() == 6 && "prior crash");
	
}





int main(){
	
	AASS::acg::AutoCompleteGraph acg(g2o::SE2(0.2, 0.1, -0.1),
		Eigen::Vector2d(0.05, 0.01), //Robot translation noise
		DEG2RAD(2.), 				//Rotation noise for robot
		Eigen::Vector2d(0.5, 0.5), //Landmarks noise
		Eigen::Vector2d(1, 0.00005), //Prior noise
		Eigen::Vector2d(0.00005, 0.00005) //Link noise,
	);
	
	prior(acg);

	acg.save("/home/malcolm/ACG_folder/martin.g2o");
	
}