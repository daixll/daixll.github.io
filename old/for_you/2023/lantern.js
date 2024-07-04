(function () {
  const WIDTH = window.innerWidth
  const HEIGHT = window.innerHeight

  const svg = document.querySelector('svg')
  svg.setAttribute('width', WIDTH)
  svg.setAttribute('height', HEIGHT)
  svg.setAttribute('viewBox', `0 0 ${WIDTH} ${HEIGHT}`)
  
  const container = document.querySelector('.lanternContainer')
  const originLantern = document.querySelector('#lantern')
  
  for (let index = 0; index < WISHES.length; index++) {
    const interval = random(0.2, 0.5) * index * 1000
    setTimeout(() => {
      const lantern = createLantern(originLantern, WISHES[index])
      container.appendChild(lantern)
    }, interval);
  }

  function createLantern(originLantern, wish) {
    const [fans, wishText] = wish
    const lantern = originLantern.cloneNode(true)
    const x = random(WIDTH * 0.1, WIDTH * 0.9)
    const y = HEIGHT
    const transformOrigin = `0 0`
    const transform = `translate(${x}, ${y})`

    lantern.setAttribute('transformOrigin', transformOrigin)
    lantern.setAttribute('transform', transform)
    lantern.setAttribute('wish', wishText)
    lantern.setAttribute('fans', fans)
    lantern.x = x
    lantern.y = y
    lantern.deltaX = random(-0.5, 0.5)
    lantern.deltaY = random(0.5, 1)
    lantern.scale = 1

    // 解开注释后孔明灯上出现用户 id
    // const text = lantern.querySelector('text')
    // const span = lantern.querySelector('.name.span')
    // text.innerHTML = fans
    // if (span) {
    //   span.innerHTML = fans
    //   if (!isMobile()) {
    //     span.className += ' gradient'
    //   }
    // }

    lantern.addEventListener('click', onLanternClick)
    return lantern
  }

  const wishContainer = document.querySelector('#wish .wish-container')
  const fansDom = document.querySelector('#wish .fans')
  const wishDom = document.querySelector('#wish .wish')
  let wishTimer = null
  function onLanternClick(event) {
    wishTimer && clearTimeout(wishTimer)
    const { currentTarget } = event
    const fans = currentTarget.getAttribute('fans')
    const wish = currentTarget.getAttribute('wish')
    fansDom.innerHTML = `—— ${fans}`
    wishDom.innerHTML = wish

    wishContainer.style.transition = 'none'
    wishContainer.style.transform = 'scale(0)'
    wishContainer.style.opacity = 0

    setTimeout(() => {
      wishContainer.style.transition = 'opacity 0.6s ease, transform 0.6s ease'
      wishContainer.style.opacity = 1
      wishContainer.style.transform = 'scale(1)'
  
      wishTimer = setTimeout(() => {
        wishContainer.style.transition = 'opacity 0.6s ease'
        wishContainer.style.opacity = 0
      }, 2000);
    }, 0);
  }

  setInterval(() => {
    const lanterns = container.children
    for (let index = 0; index < lanterns.length; index++) {
      const lantern = lanterns[index];
      let x = lantern.x + lantern.deltaX
      let y = lantern.y - lantern.deltaY
      let scale = lantern.scale
      if (y <= HEIGHT - 100) {
        scale *= 0.997
      }
      const transform = `translate(${x}, ${y}) scale(${scale}, ${scale})`
      lantern.setAttribute('transform', transform)

      if (y <= -100 || x <= -100 || x > WIDTH) {
        x = random(0, WIDTH)
        y = HEIGHT
        scale = 1
      }
      lantern.x = x
      lantern.y = y
      lantern.scale = scale
    }
  }, 16.6); // animationFrame 在高刷屏下跑太快了
})()