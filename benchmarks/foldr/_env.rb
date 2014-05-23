( (0..1000).map { |n| [n, 1] } +
  (0..400).map { |n| [10, n] }
).map { |breadth, depth|
  { breadth: breadth, depth: depth }
}