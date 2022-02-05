// 길 찾기 게임

function solution(nodeinfo) {
  for (let i = 0; i < nodeinfo.length; i++) {
    nodeinfo[i].push(i + 1)
  }

  nodeinfo = nodeinfo.sort((a, b) => {
    if (a[1] > b[1]) {
      return -1
    } else if (a[1] === b[1] && a[0] < b[0]) {
      return -1
    } else {
      return 1
    }
  })

  const [pre, post] = [[], []]

  const order = (nodes) => {
    if (nodes.length === 0) {
      return
    }

    const [left, right] = [[], []]
    const [x, y, no] = nodes[0]

    pre.push(no)

    for (let node of nodes) {
      const [cx, cy, cno] = node

      if (cx === x) {
        continue
      }

      if (cx < x) {
        left.push(node)
      } else {
        right.push(node)
      }
    }

    order(left)
    order(right)

    post.push(no)
  }

  order(nodeinfo)

  return [pre, post]
}