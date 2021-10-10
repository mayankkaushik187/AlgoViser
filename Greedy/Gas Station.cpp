//Leetcode = 134
//The idea is that ==>
/*

1 -> The total gas sum should be greater than equal to cost sum for a solution to exist
2 -> If we cannot reach


Ex -
[1,2,3,4,5] gas 
[3,4,5,1,2] cost 
Dry Run
tank += 1 - 3 = -2 , tank = 0 , start = 1
tank += 2 - 4 = -2 , tank = 0 , start = 2
tank += 3 - 5 = -2 , tank = 0 , start = 3
tank += 4 - 1 = 3 , tank = 3 , start = 3;
tank += 5 - 2 = 6 , tank = 6 , start = 3
For loop end and we return 3 ( 0 based indexing ) 
*/
int canCompleteCircuit(vector < int > & gas, vector < int > & cost) {
    int totGas = 0, totCost = 0;
    for (int i = 0; i < gas.size(); i++) {
        totGas += gas[i];
        totCost += cost[i];
    }
    if (totGas < totCost) {
        return -1;
    }
    int tank = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    return start;
}
