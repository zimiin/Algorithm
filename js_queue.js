class Queue {
  constructor() {
    this.q = {}
    this.front = 0
    this.end = -1
  }

  size() {
    return this.end - this.front + 1
  }

  push(value) {
    this.end++
    this.q[this.end] = value
  }

  popleft() {
    if (this.size() === 0) {
      return undefined
    }

    const left = this.q[this.front]
    delete this.q[this.front]
    this.front++

    if (this.end < this.front) {
      this.front = 0
      this.end = -1
    }

    return left
  }
}