//	O(n^2) Processing
class Solution {
	func canCompleteCircuit(_ gas: [Int], _ cost: [Int]) -> Int {
		if (gas.count == 0){
			return -1
		}
		var CurrentStation : Int
		var CurrentGas : Int
		var NextStation : Int
		var SuccessFound : Bool
		for start_index in 0..<gas.count{
			CurrentStation = start_index
			CurrentGas = 0
			SuccessFound = false
			for j in 0...gas.count{	
				NextStation = (CurrentStation + 1) % gas.count
				if (CurrentGas + gas[CurrentStation] - cost[CurrentStation] >= 0){
					CurrentGas = CurrentGas + gas[CurrentStation] - cost[CurrentStation]
					CurrentStation = NextStation
					if (CurrentStation == start_index){
						return start_index
					}
				}
				else {
					break
				}
			}
		}
		return -1
	}
}