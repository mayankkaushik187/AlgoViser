class Solution {
public:
    bool isRobotBounded(string instructions) {
        if(instructions.size() == 0)return false;
        string directions = "north";
        int n = instructions.size();
        int x = 0;
        int y = 0;
        for(int i= 0 ; i < n ; i++){
            if(instructions[i] == 'G'){
                if(directions == "north"){
                    x += 0;
                    y += 1;
                }else if(directions == "south"){
                    x += 0;
                    y -= 1;
                }else if(directions == "west"){
                    x -= 1;
                    y += 0;
                }else if(directions == "east"){
                    x += 1;
                    y += 0;
                }
            }else if(instructions[i] == 'L'){
                if(directions == "south"){
                    directions = "east";
                }else if(directions == "north"){
                    directions = "west";
                }else if(directions == "east"){
                    directions = "north";
                }else{
                    directions = "south";
                }
            }else{
                if(directions == "south"){
                    directions = "west";
                }else if(directions == "north"){
                    directions = "east";
                }else if(directions == "east"){
                    directions = "south";
                }else{
                    directions = "north";
                }
            }
        }
        
        if(x == 0 and y == 0){
            return true;
        }
        if(directions == "north")return false;
        
        return true;
    }
};
