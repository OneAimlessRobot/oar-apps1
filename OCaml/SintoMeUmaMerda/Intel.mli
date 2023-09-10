type intelPoint = Point of float * float * float
type growthStep = Step of intelPoint * intelPoint
type intelligence = Path of growthStep list
type task = Challenge of int | Component of task list
val x : task
val difficulty : task -> int
val ldifficulty : task list -> int
val growthDistance : growthStep -> float
val totalGrowth : intelligence -> float
val totalGrowthl : growthStep list -> float
