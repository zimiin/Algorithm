function solution(key, lock) {
  const lockSize = lock.length
  const bigLockSize = lockSize * 3
  const bigLock = [...Array(bigLockSize)].map(() => Array(bigLockSize).fill(-1))
  const keySize = key.length
  let numLockZero = 0

  for (let r = 0; r < lockSize; r++) {
    for (let c = 0; c < lockSize; c++) {
      const [bigR, bigC] = [r + lockSize, c + lockSize]
      bigLock[bigR][bigC] = lock[r][c]

      if (lock[r][c] === 0) {
        numLockZero++
      }
    }
  }

  const rotateKey = (org, angle) => {
    if (angle === 0 || angle === 360) {
      return org
    }

    const len = org.length
    const res = [...Array(len)].map(() => [])

    switch (angle) {
      case 90:
        for (let c = 0; c < len; c++) {
          for (let r = len - 1; r >= 0; r--) {
            const resRow = c
            res[resRow].push(org[r][c])
          }
        }
        break
      case 180:
        for (let r = len - 1; r >= 0; r--) {
          for (let c = len - 1; c >= 0; c--) {
            const resRow = len - r - 1
            res[resRow].push(org[r][c])
          }
        }
        break
      case 270:
        for (let c = len - 1; c >= 0; c--) {
          for (let r = 0; r < len; r++) {
            const resRow = len - c - 1
            res[resRow].push(org[r][c])
          }
        }
        break
    }
    return res
  }

  const canOpenWith = (key) => {
    for (let baseR = lockSize - keySize; baseR < bigLockSize - keySize; baseR++) {
      for (let baseC = lockSize - keySize; baseC < bigLockSize - keySize; baseC++) {
        let cntLockZero = 0
        let canOpen = true

        for (let keyR = 0; keyR < keySize; keyR++) {
          for (let keyC = 0; keyC < keySize; keyC++) {
            const lockR = baseR + keyR
            const lockC = baseC + keyC

            if (bigLock[lockR][lockC] === -1) {
              continue
            }

            if (bigLock[lockR][lockC] === key[keyR][keyC]) {
              canOpen = false
            } else if (bigLock[lockR][lockC] === 0) {
              cntLockZero++
            }
          }
        }

        if (canOpen && cntLockZero === numLockZero) {
          return true
        }
      }
    }
    return false
  }

  return (function () {
    for (let i = 0; i < 4; i++) {
      const rotatedKey = rotateKey(key, 90 * i)
      if (canOpenWith(rotatedKey)) {
        return true
      }
    }
    return false
  })()
}