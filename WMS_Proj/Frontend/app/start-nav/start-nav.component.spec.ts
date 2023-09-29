import { ComponentFixture, TestBed } from '@angular/core/testing';

import { StartNavComponent } from './start-nav.component';

describe('StartNavComponent', () => {
  let component: StartNavComponent;
  let fixture: ComponentFixture<StartNavComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ StartNavComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(StartNavComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
