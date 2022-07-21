"""
function: 在数组中找唯一重复的元素
首先定义一个字典,将字典中的元素值初始化为0,将原数组的元素逐一映射到该字典的key中
当对应的key中的value值为0时,置该key的value值为1,当对应的key的value值为1时,输出该重复的值
"""
def findDup(array):
    if array == None:
        return -1
    lens = len(array)
    HashTable = dict()
    i = 0
    while i < lens - 1:
        HashTable[i] = 0
        i += 1
    j = 0
    while j < lens:
        if HashTable[array[j] - 1] == 0:
            HashTable[array[j] - 1] = 1
        else:
            return array[i]
        j += 1
    return -1

if __name__ == "__main__":
    array = [1, 3, 4, 2, 5, 3]
    print (findDup(array))