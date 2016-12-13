class Solution {
	var isVisited = [[Bool]]()
	var isExist = false
	var board_n, board_m : Int?
	func GetNextPosition(_ I:inout Int, _ J:inout Int,_ step:Int){
		switch ( step % 4) {
		case 0:
			I += 1
			break
		case 3:
			I -= 1
		case 1:
			J -= 1
			break
		case 2:
			J += 1
		default:
			return
		}

	}
	func isInRange(_ I:Int, _ J:Int) -> Bool{
		if I>=0 && I<board_n! && J>=0 && J<board_m!
		{
			return true
		}
		return false
	}
	func GoPath(_ board:[[Character]], _ I:Int,_ J:Int,_ word: String, _ index: Int ) -> Bool {
	    isVisited[I][J] = true
		if index == word.characters.count - 1{
			return true
		}
		var isFind = false
		var next_I, next_J : Int
		for var step in 0...3{ 
			next_I = I
			next_J = J
			GetNextPosition(&next_I, &next_J, step)
			if isInRange(next_I, next_J) && isVisited[next_I][next_J]==false && board[next_I][next_J]==word[word.index(word.startIndex, offsetBy: (index+1))]{
				isFind = isFind || GoPath(board, next_I, next_J, word, index+1)
			}
		}
		isVisited[I][J] = false
		return isFind 
	}

	func exist(_ board: [[Character]], _ word: String) -> Bool {
		if (board.count==0)
		{
			return false
		}
		board_n = board.count
		print(board_n)
		board_m = board[0].count
		print(board_m)
		for var i in 1...board_n!{
			var isVisitedItem = [Bool]()
			for var j in 1...board_m!{
				isVisitedItem.append(false)
			}
			isVisited.append(isVisitedItem)
		}
		print(isVisited)
		for var indexI in 0...board_n!-1{
			for var indexJ in 0...board_m!-1{
				print (String(indexI)+" "+String(indexJ))
				if board[indexI][indexJ] == word[word.startIndex]{
					isExist = isExist || GoPath(board, indexI, indexJ, word, 0)
					if isExist{
						return isExist
					}
				}
			}
		}
		return isExist
	}
}