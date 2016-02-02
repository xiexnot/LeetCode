import os
import math

def PushHashTable(x):
	global HashTable
	HashTable[ord(x)] = 1
	return 0
	
def PopHashTable(x):
	global HashTable
	HashTable[ord(x)] = 0
	return 0
	
def CheckHashTable(x):
	# if exists, return True
	# if not exists, return False
	global HashTable
	if HashTable[ord(x)] == 1:
		return True
	else:
		return False
	
def max(a,b):
	if a>b:
		return a
	else:
		return b

def LongestSubstring(s):
	if len(s)>=1:
		maxLength = 1
	else:
		maxLength = 0
		return maxLength
	global HashTable
	HashTable = []
	for i in range(300):
		HashTable.append(0)
	
	flag_start = 0
	flag_ending = 0
	StringLength = len(s)
	PushHashTable(s[flag_start])
	while (flag_start < StringLength) and (flag_ending < StringLength):
		flag_ending += 1
		if flag_ending >= StringLength:
			break
		if CheckHashTable(s[flag_ending]) == False:
			PushHashTable(s[flag_ending])
			maxLength = max(maxLength, flag_ending - flag_start + 1)
			continue
		else:
			while (flag_start < StringLength) and (flag_ending < StringLength):
				PopHashTable(s[flag_start])
				flag_start += 1
				if CheckHashTable(s[flag_ending]) == False:
					PushHashTable(s[flag_ending])
					maxLength = max(maxLength, flag_ending - flag_start + 1)
					break
	
	return maxLength
class Solution(object):
	def lengthOfLongestSubstring(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		return LongestSubstring(s)
