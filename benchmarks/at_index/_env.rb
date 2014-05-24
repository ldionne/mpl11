(1..1000).step(2).map { |depth|
  { breadth: 1, depth: depth, index: depth-1 }
}