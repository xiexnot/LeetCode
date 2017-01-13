class Solution {
	var NumberHash = [Int]()
	func pow(_ x:Int, _ times:Int)-> Int{
		var Result: Int
		Result = 1
		for time in 1...times{
			Result = Result * x
		}
		return Result
	}
	func GetNextNumber(_ x: Int)-> Int{
		var next=0
		var current = x
		repeat{
			next = next + pow(current%10, 2)
			current = current / 10
		} while (current>0)
		return next
	}
	func isExistingNumber(_ x:Int)-> Bool{
		for item in NumberHash{
			if x == item{
				return true
			}
		}
		NumberHash.append(x)
		return false
	}
	func isHappy(_ n: Int) -> Bool {
		var CurrentN = n
		while true{
			if CurrentN == 1{
				return true
			}
			CurrentN = GetNextNumber(CurrentN)
			if isExistingNumber(CurrentN){
				break
			}
		}
		return false
	}
}