let turnOff=function(){
    let show = document.querySelector('.show')
    let showBox = show.querySelector('.showBox')
    let addBox = show.querySelector('.addBox')
    let back = show.querySelector('.back')
    back.addEventListener('click',function(){
        show.style.display = 'none';
        showBox.style.display = 'none';
        addBox.style.display = 'none';
    })
}