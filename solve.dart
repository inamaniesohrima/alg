void main() {
  List<int> input = [3, 5, 1, 2, 4, 8, 7, 6];
  print(solve(input, [0]));
}

List<int> solve(List<int> input, List<int> output) {
  if (input.length == 1) return input;
  return [];
}
