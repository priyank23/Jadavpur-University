import React, { Component } from 'react';
import 'bootstrap/dist/css/bootstrap.css';
import {Button, Container, Col, Row, Form, Navbar, Nav, Table} from 'react-bootstrap';
import './App.css';
import logo from './Wanderlust.jpg';
import { BrowserRouter, Link, Route, Switch } from 'react-router-dom';
import {faArrowRight} from "@fortawesome/free-solid-svg-icons";
import {FontAwesomeIcon} from "@fortawesome/react-fontawesome"

class Header extends Component {
  render() {
    return (
      <Navbar sticky="top" bg="light" expand="xl">
        <Navbar.Brand>
          <img
            src={logo}
            height="30"
            className="d-inline-block align-top"
            alt="Wanderlust logo"
          />{' '}
          Wanderlust</Navbar.Brand>
        <Navbar.Toggle aria-controls="basic-navbar-nav"/>
        <Navbar.Collapse id="basic-navbar-nav">
          <Nav className="mr-auto">
            <Nav.Link><Link exact to="/">Deals</Link></Nav.Link>
            <Nav.Link><Link to="/search-flights">Search Flights</Link></Nav.Link>
          </Nav>
        </Navbar.Collapse>
      </Navbar>
    )
  }
}

class FlightInfoCard extends Component {
  render() {
    return (
      <tr>
        <td>{this.props.deal.company}</td>
        <td>
          {this.props.deal.origin}{' '}<FontAwesomeIcon icon={faArrowRight}/>{' '}
          {this.props.deal.destination}
        </td>
        <td>{this.props.deal.departure}</td>
        <td>{this.props.deal.cost}</td>
        {this.props.type === "deal"? 
        <>
          <td>{this.props.deal.offerCost}</td>
          <td>{this.props.deal.validity}</td> 
        </>: null}
      </tr>
    )
  }
}

class Deals extends Component {
  constructor(props) {
    super(props)
    this.state = {
      deals: []
    }
    
  }

  componentDidMount() {
    this.fetchDeals()
  }

  fetchDeals() {
    fetch("http://localhost:8080/ass3/deals")
      .then(res => res.json())
      .then(
        (result) => {
          this.setState({deals: result})
          console.log('Deals fetched')
        },
        (error) => {
          console.log('Error fetching deals: ', error)
        }
      )
  }

  render() {
    return (
      <>
      <Table striped bordered hover variant="dark">
        <thead>
          <tr>
            <th>#</th>
            <th>Journey</th>
            <th>Departure Time</th>
            <th>Cost</th>
            <th>Offer</th>
            <th>Validity</th>
          </tr>
        </thead>
        <tbody>
          {this.state.deals.map((deal, index) => 
            <FlightInfoCard key={index} deal={deal} type="deal"/>
          )}
        </tbody>
      </Table>
      </>
    )
  }
}

class Flights extends Component {
  render() {
    return (
      <Table striped bordered hover variant="dark">
        <thead>
          <tr>
            <th>#</th>
            <th>Journey</th>
            <th>Departure Time</th>
            <th>Cost</th>
            </tr>
        </thead>
        <tbody>
          {this.props.flights.map((flight, index) => 
            <FlightInfoCard key={index} deal={flight}/>
          )}
        </tbody>
      </Table>
    )
  }
}

class FlightForm extends Component {
  constructor(props) {
    super(props)
    this.state = {
      origin: "Kolkata",
      destination: "Ranchi"
    }
    this.getFlights = this.getFlights.bind(this)
  }

  getFlights(e) {
    e.preventDefault()
    const formData = new FormData(e.target),queries = Object.fromEntries(formData.entries())
    console.log(queries)
    this.props.getFlights(queries)
  }

  render() {
    return (
      <Form className="form" onSubmit={this.getFlights}>
        <Form.Group as={Row}>
          <Col>
              <Form.Label className="label">Depart from</Form.Label>
              <Form.Control as="select" name="origin" value={this.state.origin || ""} onChange={(e)=> this.setState({origin: e.target.value})} custom>
                {["Kolkata", "Ranchi", "Siliguri", "Bangalore", "Delhi", "Dubai", "Mumbai"].map((place, index) => (
                  <option>{place}</option>
                ))}
              </Form.Control>
          </Col>
          <Col style={{float: "right"}}>
              <Form.Label className="label">Going to</Form.Label>
              <Form.Control as="select" name="destination" value={this.state.destination || ""} onChange={(e) => this.setState({destination: e.target.value})} custom>
                {["Ranchi", "Kolkata", "Siliguri", "Bangalore", "Delhi", "Dubai", "Mumbai"].map((place, index) => (
                  <option>{place}</option>
                ))}
              </Form.Control>
          </Col>
        </Form.Group>
        {this.state.origin === this.state.destination ? <Form.Text className="text-muted">Origin and destination can't be same</Form.Text>: null}
        <Form.Group as={Row}>
          <Col xs="auto">
              <Form.Label className="label">Departure Date</Form.Label>
              <Form.Control type="date" name="depart" placeholder="Departure date" /> 
          </Col>
        </Form.Group>
        <Form.Group as={Row}>
          <Col>
            <Button type="submit" className="mb-2" variant="info">Search</Button>
          </Col>
        </Form.Group>
      </Form>
    )
  }
}

class SearchFlights extends Component {
  constructor(props) {
    super(props)
    this.state={
      flights: []
    }
    this.getFlights = this.getFlights.bind(this)
  }

  getFlights(queries) {
    console.log('HERE')
    fetch('http://localhost:8080/ass3/flights', {
      method: 'POST',
      header: {'Content-Type': 'text/plain'},
      body: JSON.stringify(queries)
    })
      .then(response => response.json())
      .then(data => this.setState({flights: data}))
  }

  render() {
    return (
      <Container style={{margin: "0px"}}>
        <Row style={{width: "100vw"}}>
          <Col md={4}>
            <FlightForm getFlights={this.getFlights}/>
          </Col>
          <Col md={8}>
            <Flights flights={this.state.flights}/>
          </Col>
        </Row>
      </Container>
    )
  }
}

class App extends Component {
  render() {
    return (
      <BrowserRouter>
        <Header />
        <Switch>
          <Route exact path="/" component={Deals}/>
          <Route path="/search-flights" component={SearchFlights}/>
        </Switch>
      </BrowserRouter>
    );
  }
}

export default App;