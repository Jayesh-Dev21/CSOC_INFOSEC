def bytes2matrix(text):
    """ Converts a 16-byte array into a 4x4 matrix.  """
    return [list(text[i:i+4]) for i in range(0, len(text), 4)]

def matrix2bytes(matrix):
  chhr = ""
  for i in range (0, len(matrix)):
    for b in range (0, len(matrix[i])):
      g = matrix[i][b]
      chhr += chr(g)
  return chhr

matrix = [
    [99, 114, 121, 112],
    [116, 111, 123, 105],
    [110, 109, 97, 116],
    [114, 105, 120, 125]
  ]
  
print(matrix2bytes(matrix))